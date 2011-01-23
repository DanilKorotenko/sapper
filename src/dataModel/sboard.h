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

#ifndef SBOARD_H
#define SBOARD_H

#include <vector>

class SCell;

typedef std::vector<SCell*> SCellVector;

enum SGameCondition
{
	kSContinue = 0,
	kSBombed,
	kSWinned
};

class SBoard
{
public:
//Constructor/Destructor
	SBoard();
	SBoard(unsigned int width, unsigned int height);

	~SBoard();

//service methods
	void setSize(unsigned int width, unsigned int  height);
	unsigned int sizeX();
	unsigned int sizeY();
	SCell *getCell(unsigned int indexX, unsigned int indexY);
	bool gameOver();

//game methods
	SGameCondition makeTurn(unsigned int indexX, unsigned int indexY,
		bool setFlag);

	// Starts the checking of board from the specified cell.
	// Set to neighbours cells status checked and numbers of bombs around.
	// Iterative process. Calls this method for nested cells.
	void check(int indexX, int indexY);

	void placeBombs(unsigned int  numberOfBombs);

private:
	bool checkVictory();
	void clear();

//data
	std::vector<SCellVector> _cells;
	bool _gameOver;
};

#endif // SBOARD_H
