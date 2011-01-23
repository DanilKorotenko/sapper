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

#include <stdlib.h>
#include <time.h>

SBoard::SBoard()
{
}

SBoard::SBoard(unsigned int width, unsigned int height)
{
	this->setSize(width, height);
}

SBoard::~SBoard()
{
	this->clear();
}

void SBoard::setSize(unsigned int width, unsigned int height)
{
	this->clear();
	for (unsigned int indexY = 0; indexY < height; indexY++)
	{
		SCellVector cellsVector;
		for (unsigned int  indexX = 0; indexX < width; indexX++)
		{
			cellsVector.push_back(new SCell());
		}
		_cells.push_back(cellsVector);
	}
}

unsigned int SBoard::sizeX()
{
	return _cells.at(0).size();
}

unsigned int SBoard::sizeY()
{
	return _cells.size();
}

SCell *SBoard::getCell(unsigned int indexX, unsigned int indexY)
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

SGameCondition SBoard::makeTurn(unsigned int  indexX, unsigned int indexY,
	bool setFlag)
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

void SBoard::check(int indexX, int indexY)
{
	SCell *cell = getCell(indexX, indexY);
	if ((NULL == cell) || (cell->hasBomb()) || (cell->checked()))
	{
		return;
	}

	cell->setChecked(true);

	unsigned int numberOfBombs = 0;
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
	for (unsigned int indexX = 0; indexX != sizeX(); indexX++)
	{
		for (unsigned int indexY = 0; indexY != sizeY(); indexY++)
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

void SBoard::placeBombs(unsigned int numberOfBombs)
{
	srand(time(NULL));
	for (unsigned int bombIndex = 0; bombIndex < numberOfBombs; )
	{
		unsigned int x = rand() % sizeX();
		unsigned int y = rand() % sizeY();
		SCell *cell = getCell(x, y);
		if ((cell != NULL) && (!cell->hasBomb()))
		{
			cell->setHasBomb(true);
			bombIndex++;
		}
	}
}

void SBoard::clear()
{
	_gameOver = false;
	for (unsigned int indexY = 0; indexY != sizeY(); indexY++)
	{
		for (unsigned int indexX = 0; indexX != sizeX(); indexX++)
		{
			delete getCell(indexX, indexY);
		}
	}
	_cells.clear();
}
