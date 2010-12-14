#include "dataModelTest.h"

#include "scell.h"

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
	//Verify initial state
	for (QVector<SCellVector>::const_iterator iteratorX = _board->_cells.begin();
		iteratorX != _board->_cells.end(); iteratorX++)
	{
		for (SCellVector::const_iterator iteratorY = (*iteratorX).begin();
			iteratorY != (*iteratorX).end(); iteratorY++)
		{
			QCOMPARE((*iteratorY)->hasBomb(), false);
			QCOMPARE((*iteratorY)->checked(), false);
			QCOMPARE((*iteratorY)->marked(), false);
			QCOMPARE((*iteratorY)->numberOfBombsArround(), (qint8)0);
		}
	}
}

void DataModelTest::testMarkUnMark()
{
	SCell *cell = _board->_cells.at(0).at(0);

	cell->setHasBomb(true);
	QCOMPARE(cell->hasBomb(), true);

	cell->toggleMark();
	QCOMPARE(cell->marked(), true);

	cell->toggleMark();
	QCOMPARE(cell->marked(), false);
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
	_board->_cells.at(0).at(0)->toggleMark();
	QCOMPARE(_board->checkVictory(), false);
	_board->_cells.at(1).at(1)->toggleMark();
	QCOMPARE(_board->checkVictory(), true);

}

void DataModelTest::testMakeTurn()
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
	//
}

void DataModelTest::testCellsChecking()
{

}

void DataModelTest::cleanup()
{
	delete _board;
}

QTEST_MAIN(DataModelTest)
