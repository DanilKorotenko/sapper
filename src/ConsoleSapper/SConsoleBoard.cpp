/*******************************************************************
 Copyright (C) 2011 Danil Korotenko (danil.korotenko@gmail.com)

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public Licence
 as published by the Free Software Foundation; either version 3
 of the Licence, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public Licence for more details.

 You should have received a copy of the GNU General Public Licence
 along with this program; if not, write to the Free Software Foundation,
 Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
********************************************************************/

#include "SConsoleBoard.h"

#include "dataModel/scell.h"
#include "SConsoleCell.h"

static QString const abc = "abcdefghijklmnopqrstuvwxyz";

SConsoleBoard::SConsoleBoard(QObject *parent) : SBoard(parent)
{

}

SConsoleBoard::SConsoleBoard(quint8 width, quint8 height, QObject *parent) :
	SBoard(width, height, parent)
{

}

SGameCondition SConsoleBoard::makeTurn(quint8 indexX, quint8 indexY, bool setFlag)
{
	return SBoard::makeTurn(indexX, indexY, setFlag);
}


SGameCondition SConsoleBoard::makeTurn(QString turnDescription)
{
	//turnDescription is a string that contains a three or two characters:
	//1st - letter - the x coordinate
	//2nd - digit - the y coordinate
	//[3rd] - 'f' place flag or no

	SGameCondition result = kSContinue;

	quint8 indexX = 0;
	quint8 indexY = 0;
	QChar firstCharacter = turnDescription.at(0);
	QChar secondCharacter = turnDescription.at(1);

	if (firstCharacter.isLetter())
	{
		indexY = abc.indexOf(firstCharacter);
		if (indexY != -1)
		{
			if (secondCharacter.isDigit())
			{
				indexX = secondCharacter.digitValue();
				if (3 == turnDescription.length())
				{
					result = SBoard::makeTurn(indexX, indexY, true);
				}
				else if (2 == turnDescription.length())
				{
					result = SBoard::makeTurn(indexX, indexY, false);
				}
			}
		}
	}

	return result;
}


QString SConsoleBoard::stringRepresentation()
{
	QString result = QString("");

	if((_cells.value(0).count() > abc.length()) ||
		(_cells.count() > 10))
	{
		result.append("The board cannot be printed.\n");
	}
	else
	{
		//print ' a b c'
		result.append("  ");
		for (quint8 xSize = 0; xSize < _cells.value(0).count(); xSize++)
		{
			result.append(QString(" %1").arg(abc.at(xSize)));
		}
		result.append("\n");
		quint8 cellNumber = 0;
		for (QVector<SCellVector>::const_iterator iteratorX = _cells.begin();
			iteratorX != _cells.end(); iteratorX++)
		{
			//print '  - - - -'
			result.append("  ");
			for (SCellVector::const_iterator iteratorY = (*iteratorX).begin();
				iteratorY != (*iteratorX).end(); iteratorY++)
			{
				result.append(" -");
			}
			result.append("\n");
			result.append(QString("%1 ").arg(cellNumber));
			cellNumber++;
			for (SCellVector::const_iterator iteratorY = (*iteratorX).begin();
				iteratorY != (*iteratorX).end(); iteratorY++)
			{
				result.append("|");
				SConsoleCell *consoleCell = (SConsoleCell *)(*iteratorY);
				result.append(consoleCell->stringRepresentation(_gameOver));
			}
			result.append("|\n");
		}
		//print ' - - - -'
		result.append("  ");
		for (quint8 xSize = 0; xSize < _cells.value(0).count(); xSize++)
		{
			result.append(" -");
		}
		result.append("\n");
	}

	return result;
}

SCell *SConsoleBoard::createCell()
{
	return new SConsoleCell();
}

