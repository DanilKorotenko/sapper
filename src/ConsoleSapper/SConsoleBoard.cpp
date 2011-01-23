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

SConsoleBoard::SConsoleBoard(QObject *parent) : QObject(parent)
{
	board = new SBoard();
}

SConsoleBoard::SConsoleBoard(uint width, uint height, QObject *parent) :
	QObject(parent)
{
	board = new SBoard(width, height);
}

SConsoleBoard::~SConsoleBoard()
{
	delete board;
}

void SConsoleBoard::placeBombs(quint8 numberOfBombs)
{
	board->placeBombs(numberOfBombs);
}

SGameCondition SConsoleBoard::makeTurn(QString turnDescription)
{
	//turnDescription is a string that contains a three or two characters:
	//1st - letter - the x coordinate
	//2nd - digit - the y coordinate
	//[3rd] - 'f' place flag or no

	SGameCondition result = kSContinue;

	int indexX = 0;
	int indexY = 0;
	QChar firstCharacter = turnDescription.at(0);
	QChar secondCharacter = turnDescription.at(1);

	if (firstCharacter.isLetter())
	{
		indexX = abc.indexOf(firstCharacter);
		if (indexX != -1)
		{
			if (secondCharacter.isDigit())
			{
				indexY = secondCharacter.digitValue();
				if (3 == turnDescription.length())
				{
					result = board->makeTurn(indexX, indexY, true);
				}
				else if (2 == turnDescription.length())
				{
					result = board->makeTurn(indexX, indexY, false);
				}
			}
		}
	}
	return result;
}

void SConsoleBoard::setSize(quint8 width, quint8 height)
{
	board->setSize(width, height);
}

void SConsoleBoard::setBomb(quint8 x, quint8 y)
{
	board->getCell(x,y)->setHasBomb(true);
}


QString SConsoleBoard::stringRepresentation()
{
	QString result = QString("");

	if((board->sizeX() > (uint)abc.length()) || (board->sizeY() > 10))
	{
		result.append("The board cannot be printed.\n");
	}
	else
	{
		//print ' a b c'
		result.append("  ");
		for (uint indexX = 0; indexX < board->sizeX(); indexX++)
		{
			result.append(QString(" %1").arg(abc.at(indexX)));
		}
		result.append("\n");

		for (uint indexY = 0; indexY < board->sizeY(); indexY++)
		{
			//print '  - - - -'
			result.append("  ");
			for (uint indexX = 0; indexX < board->sizeX(); indexX++)
			{
				result.append(" -");
			}
			result.append("\n");

			result.append(QString("%1 ").arg(indexY));
			for (uint indexX = 0; indexX < board->sizeX(); indexX++)
			{
				result.append("|");
				SCell *cell = board->getCell(indexX, indexY);
				result.append(this->stringRepresentationForCell(cell,
					board->gameOver()));
			}
			result.append("|\n");
		}
		//print ' - - - -'
		result.append("  ");
		for (uint indexX = 0; indexX < board->sizeX(); indexX++)
		{
			result.append(" -");
		}
		result.append("\n");
	}

	return result;
}

QString SConsoleBoard::stringRepresentationForCell(SCell *cell, bool gameOver)
{
	QString result;

	if (cell->checked())
	{
		if (0 == cell->numberOfBombs())
		{
			result = " ";
		}
		else
		{
			result.append(QString("%1").arg(cell->numberOfBombs()));
		}
	}
	else if (gameOver)
	{
		if (cell->flagged())
		{
			if (cell->hasBomb())
			{
				result = "F";
			}
			else
			{
				result = "-";
			}
		}
		else if (cell->hasBomb())
		{
			result = "*";
		}
		else
		{
			result = " ";
		}
	}
	else if (cell->flagged())
	{
		result = "F";
	}
	else
	{
		result = "?";
	}

	return result;
}

