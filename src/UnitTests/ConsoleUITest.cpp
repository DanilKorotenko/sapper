#include "ConsoleUITest.h"

#include <QTest>

#include "ConsoleApplication/SConsoleBoard.h"

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
	QString boardStringRepresentation(" - -\n"
									  "| | |\n"
									  " - -\n"
									  "| | |\n"
									  " - -\n");

	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);
}

void ConsoleUITest::cleanup()
{
	delete _consoleBoard;
}
