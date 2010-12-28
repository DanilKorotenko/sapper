#include "STerminalBoard.h"

#include "dataModel/scell.h"

STerminalBoard::STerminalBoard(QObject *parent) : SBoard(parent)
{

}

STerminalBoard::STerminalBoard(quint8 width, quint8 height, QObject *parent) :
	SBoard(width, height, parent)
{

}

QString STerminalBoard::stringRepresentation()
{
	QString result;

	for (QVector<SCellVector>::const_iterator iteratorX = _cells.begin();
		iteratorX != _cells.end(); iteratorX++)
	{
		//print ' - - - - '
		for (SCellVector::const_iterator iteratorY = (*iteratorX).begin();
			iteratorY != (*iteratorX).end(); iteratorY++)
		{
			result.append(" -");
		}
		result.append("\n");
		for (SCellVector::const_iterator iteratorY = (*iteratorX).begin();
			iteratorY != (*iteratorX).end(); iteratorY++)
		{
			result.append("|");
			if ((*iteratorY)->hasBomb())
			{
				result.append("*");
			}
			else
			{
				result.append(" ");
			}
		}
		result.append("|\n");
	}
	//print ' - - - -'
	for (quint8 xSize = 0; xSize < _cells.value(0).count(); xSize++)
	{
		result.append(" -");
	}
	result.append("\n");

	return result;
}
