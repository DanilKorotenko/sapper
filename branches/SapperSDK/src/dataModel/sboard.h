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

#include <QObject>
#include <QVector>

#include <stdlib.h>

class SCell;

typedef std::vector<SCell *> SCellVector;

enum SGameCondition
{
	kSContinue = 0,
	kSBombed,
	kSWinned
};

class SBoard : public QObject
{
	Q_OBJECT
public:
//Constructor/Destructor
	explicit SBoard(QObject *parent = 0);
	SBoard(uint width, uint height, QObject *parent = 0);

	~SBoard();

//service methods
	void setSize(uint width, uint height);
	uint sizeX();
	uint sizeY();
	SCell *getCell(uint indexX, uint indexY);

//game methods
	SGameCondition makeTurn(uint indexX, uint indexY, bool setFlag);

	// Starts the checking of board from the specified cell.
	// Set to neighbours cells status checked and numbers of bombs around.
	// Iterative process. Calls this method for nested cells.
	void check(qint8 indexX, qint8 indexY);

	bool checkVictory();

	void placeBombs(uint numberOfBombs);

protected:
	SCell *createCell();

	bool _gameOver;
private:
	void clear();

//data
	std::vector<SCellVector> _cells;
};

#endif // SBOARD_H
