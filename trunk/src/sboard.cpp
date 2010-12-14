#include "sboard.h"

#include "scell.h"

#include <QPointer>

SBoard::SBoard(quint8 width, quint8 height, QObject *parent) : QObject(parent)
{
	for (quint8 indexX = 0; indexX < width; indexX++)
	{
		SCellVector cellsVector;
		for (quint8 indexY = 0; indexY < height; indexY++)
		{
			QPointer<SCell> cell = new SCell(this);
			cellsVector.push_back(cell);
		}
		_cells.push_back(cellsVector);
	}
}

SGameCondition SBoard::makeTurn(quint8 indexX, quint8 indexY, bool setFlag)
{
	SGameCondition result = kSContinue;
	SCell *cell = _cells.at(indexX).at(indexY);
	if (setFlag)
	{
		cell->toggleMark();
		if (this->checkVictory())
		{
			result = kSWinned;
		}
	}
	else if (cell->hasBomb())
	{
		result = kSBombed;
	}
	else
	{

	}
	return result;
}

void SBoard::check(quint8 indexX, quint8 indexY)
{

}

bool SBoard::checkVictory()
{
	bool result = true;
	for (QVector<SCellVector>::const_iterator iteratorX = _cells.begin();
		iteratorX != _cells.end(); iteratorX++)
	{
		for (SCellVector::const_iterator iteratorY = (*iteratorX).begin();
			iteratorY != (*iteratorX).end(); iteratorY++)
		{
			if ((*iteratorY)->hasBomb())
			{
				result = (*iteratorY)->marked() && result;
			}
		}
	}
	return result;
}

