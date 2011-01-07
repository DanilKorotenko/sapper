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
	QCOMPARE(_board->_cells.count(), 8);

	//test the board has specified size
	for (QVector<SCellVector>::const_iterator iteratorX = _board->_cells.begin();
		iteratorX != _board->_cells.end(); iteratorX++)
	{
		QCOMPARE((*iteratorX).count(), 8);
	}

	//test the board has correct initial state after creation.
	this->verifyInitialState();
}

// Game process tests

void DataModelTest::testMarkUnMark()
{
	SCell *cell = _board->_cells.at(0).at(0);

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

	_board->_cells.at(0).at(0)->setHasBomb(true);
	QCOMPARE(_board->checkVictory(), false);
	_board->_cells.at(1).at(1)->setHasBomb(true);
	QCOMPARE(_board->checkVictory(), false);
	_board->_cells.at(0).at(0)->toggleFlag();
	QCOMPARE(_board->checkVictory(), false);
	_board->_cells.at(1).at(1)->toggleFlag();
	QCOMPARE(_board->checkVictory(), true);
}

void DataModelTest::testMakeWinnerTurn()
{
//  - -
// |*| |
//  - -
// | | |
//  - -
	_board->_cells.at(0).at(0)->setHasBomb(true);
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
	_board->_cells.at(0).at(0)->setHasBomb(true);
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
	_board->_cells.at(0).at(0)->setHasBomb(true);
	QCOMPARE(_board->makeTurn(0,1,false), kSContinue);

	QCOMPARE(_board->_cells.at(0).at(1)->numberOfBombs(), (quint8)1);
	QCOMPARE(_board->_cells.at(0).at(1)->checked(), true);
	QCOMPARE(_board->_cells.at(1).at(1)->numberOfBombs(), (quint8)0);
	QCOMPARE(_board->_cells.at(1).at(1)->checked(), false);
	QCOMPARE(_board->_cells.at(1).at(0)->numberOfBombs(), (quint8)0);
	QCOMPARE(_board->_cells.at(1).at(0)->checked(), false);

	QCOMPARE(_board->makeTurn(1,1,false), kSContinue);
	QCOMPARE(_board->_cells.at(1).at(1)->numberOfBombs(), (quint8)1);
	QCOMPARE(_board->_cells.at(1).at(1)->checked(), true);

	QCOMPARE(_board->makeTurn(1,0,false), kSContinue);
	QCOMPARE(_board->_cells.at(1).at(0)->numberOfBombs(), (quint8)1);
	QCOMPARE(_board->_cells.at(1).at(0)->checked(), true);

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
	for (QVector<SCellVector>::const_iterator iteratorX = _board->_cells.begin();
		iteratorX != _board->_cells.end(); iteratorX++)
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

