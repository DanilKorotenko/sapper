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

#include "dataModelTest.h"

#include <QTest>

#include "dataModel/sboard.h"
#include "dataModel/scell.h"

void DataModelTest::init()
{
//Create a game board with size 2x2
//  - -
// | | |
//  - -
// | | |
//  - -

	qint8 boardXSize = 2;
	qint8 boardYSize = 2;

	_board = new SBoard(boardXSize, boardYSize);

	QVERIFY(!_board.isNull());
}

void DataModelTest::testBoardCreation()
{
	this->verifyInitialState();
}

void DataModelTest::testBoardResizing()
{
	_board->setSize(8,8);
	QCOMPARE(_board->cells().count(), 8);

	//test the board has specified size
	for (QVector<SCellVector>::const_iterator iteratorX =
		_board->cells().begin(); iteratorX != _board->cells().end();
		iteratorX++)
	{
		QCOMPARE((*iteratorX).count(), 8);
	}

	//test the board has correct initial state after creation.
	this->verifyInitialState();
}

// Game process tests

void DataModelTest::testMarkUnMark()
{
	SCell *cell = _board->cells().value(0).value(0, NULL);

	cell->setHasBomb(true);
	QCOMPARE(cell->hasBomb(), true);

	cell->toggleFlag();
	QCOMPARE(cell->flagged(), true);

	cell->toggleFlag();
	QCOMPARE(cell->flagged(), false);
}

void DataModelTest::testCheckVictory()
{
//place bombs on a board
//  - -
// |*| |
//  - -
// | |*|
//  - -

	_board->cells().value(0).value(0, NULL)->setHasBomb(true);
	QCOMPARE(_board->checkVictory(), false);
	_board->cells().value(1).value(1, NULL)->setHasBomb(true);
	QCOMPARE(_board->checkVictory(), false);
	_board->cells().value(0).value(0, NULL)->toggleFlag();
	QCOMPARE(_board->checkVictory(), false);
	_board->cells().value(1).value(1, NULL)->toggleFlag();
	QCOMPARE(_board->checkVictory(), true);
}

void DataModelTest::testMakeWinnerTurn()
{
//  - -
// |*| |
//  - -
// | | |
//  - -
	_board->cells().value(0).value(0, NULL)->setHasBomb(true);
	QCOMPARE(_board->makeTurn(0,0,true), kSWinned);

	//TODO: when the game condition become 'winned' there are no other turns
	// player can make
	// Need to test this condition

}

void DataModelTest::testGameOverTurn()
{
//  - -
// |*| |
//  - -
// | | |
//  - -
	_board->cells().value(0).value(0, NULL)->setHasBomb(true);
	QCOMPARE(_board->makeTurn(0,0,false), kSBombed);

	//TODO: when the game condition become 'winned' there are no other turns
	// player can make
	// Need to test this condition

}

void DataModelTest::testCellsChecking()
{
//  - -
// |*| |
//  - -
// | | |
//  - -
	_board->cells().value(0).value(0, NULL)->setHasBomb(true);
	QCOMPARE(_board->makeTurn(0,1,false), kSContinue);

	QCOMPARE(_board->cells().value(0).value(1, NULL)->numberOfBombs(),
		(quint8)1);
	QCOMPARE(_board->cells().value(0).value(1, NULL)->checked(), true);
	QCOMPARE(_board->cells().value(1).value(1, NULL)->numberOfBombs(),
		(quint8)0);
	QCOMPARE(_board->cells().value(1).value(1, NULL)->checked(), false);
	QCOMPARE(_board->cells().value(1).value(0, NULL)->numberOfBombs(),
		(quint8)0);
	QCOMPARE(_board->cells().value(1).value(0, NULL)->checked(), false);

	QCOMPARE(_board->makeTurn(1,1,false), kSContinue);
	QCOMPARE(_board->cells().value(1).value(1, NULL)->numberOfBombs(),
		(quint8)1);
	QCOMPARE(_board->cells().value(1).value(1, NULL)->checked(), true);

	QCOMPARE(_board->makeTurn(1,0,false), kSContinue);
	QCOMPARE(_board->cells().value(1).value(0, NULL)->numberOfBombs(),
		(quint8)1);
	QCOMPARE(_board->cells().value(1).value(0, NULL)->checked(), true);

	QCOMPARE(_board->makeTurn(0,0,true), kSWinned);
}

void DataModelTest::testBombsPlacing()
{
	_board->setSize(5,5);
	_board->placeBombs(5);
	//TODO: need to add some virifying here.
}

void DataModelTest::verifyInitialState()
{
	//Verify initial state
	//test if we have access to all cells, and all cells has correct state.
	for (QVector<SCellVector>::const_iterator iteratorX =
		_board->cells().begin(); iteratorX != _board->cells().end();
		iteratorX++)
	{
		for (SCellVector::const_iterator iteratorY = (*iteratorX).begin();
			iteratorY != (*iteratorX).end(); iteratorY++)
		{
			QCOMPARE((*iteratorY)->hasBomb(), false);
			QCOMPARE((*iteratorY)->checked(), false);
			QCOMPARE((*iteratorY)->flagged(), false);
			QCOMPARE((*iteratorY)->numberOfBombs(), (quint8)0);
		}
	}
}

void DataModelTest::cleanup()
{
	delete _board;
}

