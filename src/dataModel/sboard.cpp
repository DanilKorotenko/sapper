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
		cell->toggleFlag();
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
		this->check(indexX, indexY);
	}
	return result;
}

void SBoard::check(qint8 indexX, qint8 indexY)
{
	SCell *cell = _cells.value(indexX).value(indexY, NULL);
	if ((NULL == cell) || (cell->hasBomb()) || (cell->checked()))
	{
		return;
	}
	cell->toggleChecked();
	quint8 numberOfBombs = 0;
	for(qint8 cellIndexX = indexX-1; cellIndexX <= indexX + 1; cellIndexX++)
	{
		for(qint8 cellIndexY = indexY-1; cellIndexY <= indexY + 1;
			cellIndexY++)
		{
			SCell *tempCell = _cells.value(cellIndexX).value(cellIndexY, NULL);
			if ((NULL != tempCell) && (tempCell->hasBomb()))
			{
				numberOfBombs++;
			}
		}
	}

	cell->setNumberOfBombsArround(numberOfBombs);

	if (0 == numberOfBombs)
	{
		for(quint8 cellIndexX = indexX-1; cellIndexX <= indexX + 1;
			cellIndexX++)
		{
			for(quint8 cellIndexY = indexY-1; cellIndexY <= indexY + 1;
				cellIndexY++)
			{
				this->check(cellIndexX, cellIndexY);
			}
		}
	}
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
				//check if cell has bomb and flag
				result = (*iteratorY)->flagged() && result;
			}
		}
	}
	return result;
}

