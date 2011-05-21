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

#include "DataModel.h"

#include <QObject>
#include <QVector>

class SCell;

typedef QVector<SCell *> SCellVector;

enum SGameCondition
{
	kSContinue = 0,
	kSBombed,
	kSWinned
};

class DATAMODELSHARED_EXPORT SBoard : public QObject
{
	Q_OBJECT
public:
//Constructor/Destructor
	explicit SBoard(QObject *parent = 0);
	SBoard(quint8 width, quint8 height, QObject *parent = 0);

	~SBoard();

//service methods
	void setSize(quint8 width, quint8 height);
	QVector<SCellVector> cells() const;

//game methods
	SGameCondition makeTurn(quint8 indexX, quint8 indexY, bool setFlag);

	// Starts the checking of board from the specified cell.
	// Set to neighbours cells status checked and numbers of bombs around.
	// Iterative process. Calls this method for nested cells.
	void check(qint8 indexX, qint8 indexY);

	bool checkVictory();

	void placeBombs(quint8 numberOfBombs);

protected:
	SCell *createCell();

	bool _gameOver;
	QVector<SCellVector> _cells;

private:
	void clear();

};

#endif // SBOARD_H
