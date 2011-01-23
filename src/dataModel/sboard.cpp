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

#include <time.h>

SBoard::SBoard(QObject *parent) : QObject(parent)
{
}

SBoard::SBoard(uint width, uint height, QObject *parent) : QObject(parent)
{
	this->setSize(width, height);
}

SBoard::~SBoard()
{
	this->clear();
}

void SBoard::setSize(uint width, uint height)
{
	this->clear();
	for (uint indexY = 0; indexY < height; indexY++)
	{
		SCellVector cellsVector;
		for (uint indexX = 0; indexX < width; indexX++)
		{
			SCell *cell = this->createCell();
			cellsVector.push_back(cell);
		}
		_cells.push_back(cellsVector);
	}
}

uint SBoard::sizeX()
{
	return _cells.at(0).size();
}

uint SBoard::sizeY()
{
	return _cells.size();
}

SCell *SBoard::getCell(uint indexX, uint indexY)
{
	SCell *result = NULL;
	if((indexX >= 0) && (indexX < sizeX()) &&
		(indexY >= 0) && (indexY < sizeY()))
	{
		result = _cells.at(indexY).at(indexX);
	}

	return result;
}

bool SBoard::gameOver()
{
	return _gameOver;
}

SGameCondition SBoard::makeTurn(uint indexX, uint indexY, bool setFlag)
{
	SGameCondition result = kSContinue;
	SCell *cell = getCell(indexX, indexY);
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
	SCell *cell = getCell(indexX, indexY);
	if ((NULL == cell) || (cell->hasBomb()) || (cell->checked()))
	{
		return;
	}

	cell->setChecked(true);

	uint numberOfBombs = 0;
	for(int cellIndexX = indexX-1; cellIndexX <= indexX + 1; cellIndexX++)
	{
		for(int cellIndexY = indexY-1; cellIndexY <= indexY + 1;
			cellIndexY++)
		{
			SCell *tempCell = getCell(cellIndexX, cellIndexY);
			if ((NULL != tempCell) && (tempCell->hasBomb()))
			{
				numberOfBombs++;
			}
		}
	}

	cell->setNumberOfBombsArround(numberOfBombs);

	if (0 == numberOfBombs)
	{
		for(int cellIndexX = indexX-1; cellIndexX <= indexX + 1;
			cellIndexX++)
		{
			for(int cellIndexY = indexY-1; cellIndexY <= indexY + 1;
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
	for (uint indexX = 0; indexX != sizeX(); indexX++)
	{
		for (uint indexY = 0; indexY != sizeY(); indexY++)
		{
			SCell *cell = this->getCell(indexX, indexY);
			if (cell->hasBomb())
			{
				//check if cell has bomb and flag
				result = cell->flagged() && result;
			}
		}
	}
	return result;
}

void SBoard::placeBombs(uint numberOfBombs)
{
	srand(time(NULL));
	for (uint bombIndex = 0; bombIndex < numberOfBombs; )
	{
		uint x = rand() % sizeX();
		uint y = rand() % sizeY();
		SCell *cell = getCell(x, y);
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
	for (uint indexY = 0; indexY != sizeY(); indexY++)
	{
		for (uint indexX = 0; indexX != sizeX(); indexX++)
		{
			delete getCell(indexX, indexY);
		}
	}
	_cells.clear();
}
