#include "ConsoleUITest.h"

#include <QTest>

#include "ConsoleApplication/SConsoleBoard.h"
#include "dataModel/scell.h"

void ConsoleUITest::init()
{
//Create a game board with size 2x2
//  - -
// | | |
//  - -
// | | |
//  - -

	_consoleBoard = new SConsoleBoard(2,2);

	QVERIFY(!_consoleBoard.isNull());
}

void ConsoleUITest::testBoardDisplaying()
{
	QString boardStringRepresentation("   a b\n"
									  "   - -\n"
									  "0 | | |\n"
									  "   - -\n"
									  "1 | | |\n"
									  "   - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);

	_consoleBoard->setSize(3,2);
	boardStringRepresentation = ("   a b c\n"
								 "   - - -\n"
								 "0 | | | |\n"
								 "   - - -\n"
								 "1 | | | |\n"
								 "   - - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);

	_consoleBoard->setSize(2,3);
	boardStringRepresentation = ("   a b\n"
								 "   - -\n"
								 "0 | | |\n"
								 "   - -\n"
								 "1 | | |\n"
								 "   - -\n"
								 "2 | | |\n"
								 "   - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);
}

void ConsoleUITest::testBigBoardDisplaying()
{
	QString boardStringRepresentation("The board cannot be printed.\n");
	_consoleBoard->setSize(27,2);
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);
	_consoleBoard->setSize(2,11);
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);
}

void ConsoleUITest::testBoardInGameDisplayingGameOver()
{
	QString boardStringRepresentation("   a b\n"
									  "   - -\n"
									  "0 | | |\n"
									  "   - -\n"
									  "1 | | |\n"
									  "   - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);
	_consoleBoard->_cells.value(0).value(0, NULL)->setHasBomb(true);
//	QCOMPARE(_consoleBoard->stringRepresentation(),
//		boardStringRepresentation);

	_consoleBoard->makeTurn(0,0,false);

	boardStringRepresentation = ("   a b\n"
								 "   - -\n"
								 "0 |*| |\n"
								 "   - -\n"
								 "1 | | |\n"
								 "   - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);
}

void ConsoleUITest::testBoardInGameDisplayingWin()
{

}

void ConsoleUITest::cleanup()
{
	delete _consoleBoard;
}
