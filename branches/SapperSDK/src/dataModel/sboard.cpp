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

#include "sboard.h"

#include "scell.h"

#include <QPointer>
#include <QDateTime>

SBoard::SBoard(QObject *parent) : QObject(parent)
{
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

QVector<SCellVector> SBoard::cells() const
{
	return _cells;
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

	cell->setChecked(true);

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
		for(qint8 cellIndexX = indexX-1; cellIndexX <= indexX + 1;
			cellIndexX++)
		{
			for(qint8 cellIndexY = indexY-1; cellIndexY <= indexY + 1;
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

void SBoard::placeBombs(quint8 numberOfBombs)
{
	qsrand(QDateTime::currentMSecsSinceEpoch());
	quint8 sizeX = _cells.count();
	quint8 sizeY = _cells.value(0).count();
	for (quint8 bombIndex = 0; bombIndex < numberOfBombs; )
	{
		quint8 x = qrand() % sizeX;
		quint8 y = qrand() % sizeY;
		SCell *cell = _cells.value(x).value(y,NULL);
		if ((cell != NULL) && (!cell->hasBomb()))
		{
			cell->setHasBomb(true);
			bombIndex++;
		}
	}
}

SCell *SBoard::createCell()
{
	return new SCell();
}

void SBoard::clear()
{
	_gameOver = false;
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
