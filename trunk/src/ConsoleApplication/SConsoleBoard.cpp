#include "SConsoleBoard.h"

#include "dataModel/scell.h"
#include "SConsoleCell.h"

SConsoleBoard::SConsoleBoard(QObject *parent) : SBoard(parent)
{

}

SConsoleBoard::SConsoleBoard(quint8 width, quint8 height, QObject *parent) :
	SBoard(width, height, parent)
{

}

QString SConsoleBoard::stringRepresentation()
{
	QString result;
	QString abc("abcdefghijklmnopqrstuvwxyz");

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

