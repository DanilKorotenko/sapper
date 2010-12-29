#include "sboard.h"

#include "scell.h"

#include <QPointer>

SBoard::SBoard(QObject *parent) : QObject(parent)
{
	_gameOver = false;
}

SBoard::SBoard(quint8 width, quint8 height, QObject *parent) : QObject(parent)
{
	this->setSize(width, height);
}

SBoard::~SBoard()
{
	this->clear();
}

void SBoard::setSize(quint8 width, quint8 height)
{
	this->clear();
	for (quint8 indexX = 0; indexX < height; indexX++)
	{
		SCellVector cellsVector;
		for (quint8 indexY = 0; indexY < width; indexY++)
		{
			QPointer<SCell> cell = this->createCell();
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
			_gameOver = true;
		}
	}
	else if (cell->hasBomb())
	{
		result = kSBombed;
		_gameOver = true;
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

SCell *SBoard::createCell()
{
	return new SCell();
}

void SBoard::clear()
{
	for (QVector<SCellVector>::const_iterator iteratorX = _cells.begin();
		iteratorX != _cells.end(); iteratorX++)
	{
		for (SCellVector::const_iterator iteratorY = (*iteratorX).begin();
			iteratorY != (*iteratorX).end(); iteratorY++)
		{
			delete (*iteratorY);
		}
	}
	_cells.clear();
}
