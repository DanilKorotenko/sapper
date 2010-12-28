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

//	qint8 boardXSize = 2;
//	qint8 boardYSize = 2;

	_terminalBoard = new STerminalBoard();

	QVERIFY(!_terminalBoard.isNull());
}

void TerminalUITest::testBoardDisplaying()
{

}

void TerminalUITest::cleanup()
{
	delete _terminalBoard;
}
