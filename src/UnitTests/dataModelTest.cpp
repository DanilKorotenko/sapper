#include "dataModelTest.h"

#include <QPointer>

#include "sboard.h"
#include "scell.h"

void DataModelTest::testCorrectBoardCreation()
{
//Create a game board with size 2x2
//  - -
// | | |
//  - -
// | | |
//  - -

	qint8 boardXSize = 2;
	qint8 boardYSize = 2;

	QPointer<SBoard> board = new SBoard(boardXSize, boardYSize);

	QVERIFY(NULL != board); //correct created board must not be nil

	//Verify initial state
	for (qint8 indexX = 0; indexX < boardXSize; indexX++)
	{
		for (qint8 indexY = 0; indexY < boardYSize; indexY++)
		{
			QCOMPARE(board->cells().at(indexX).at(indexY)->hasBomb(), false);
			QCOMPARE(board->cells().at(indexX).at(indexY)->checked(), false);
			QCOMPARE(board->cells().at(indexX).at(indexY)->numberOfBombsArround(),
				(qint8)0);
		}
	}

	delete board;
}

QTEST_MAIN(DataModelTest)
