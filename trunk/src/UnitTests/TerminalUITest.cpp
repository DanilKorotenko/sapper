#include "TerminalUITest.h"

#include <QTest>

#include "ui/terminal/STerminalBoard.h"

void TerminalUITest::init()
{
//Create a game board with size 2x2
//  - -
// | | |
//  - -
// | | |
//  - -

	_terminalBoard = new STerminalBoard(2,2);

	QVERIFY(!_terminalBoard.isNull());
}

void TerminalUITest::testBoardDisplaying()
{
	QString boardStringRepresentation(" - -\n"
									  "| | |\n"
									  " - -\n"
									  "| | |\n"
									  " - -\n");

	QCOMPARE(_terminalBoard->stringRepresentation(),
		boardStringRepresentation);
}

void TerminalUITest::cleanup()
{
	delete _terminalBoard;
}
