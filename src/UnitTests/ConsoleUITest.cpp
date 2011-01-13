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

#include "ConsoleUITest.h"

#include <QTest>

#include "ConsoleSapper/SConsoleBoard.h"
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
									  "0 |?|?|\n"
									  "   - -\n"
									  "1 |?|?|\n"
									  "   - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);

	_consoleBoard->setSize(3,2);
	boardStringRepresentation = ("   a b c\n"
								 "   - - -\n"
								 "0 |?|?|?|\n"
								 "   - - -\n"
								 "1 |?|?|?|\n"
								 "   - - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);

	_consoleBoard->setSize(2,3);
	boardStringRepresentation = ("   a b\n"
								 "   - -\n"
								 "0 |?|?|\n"
								 "   - -\n"
								 "1 |?|?|\n"
								 "   - -\n"
								 "2 |?|?|\n"
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

void ConsoleUITest::testBoardDisplayingGameOver()
{
	QString boardStringRepresentation("   a b\n"
									  "   - -\n"
									  "0 |?|?|\n"
									  "   - -\n"
									  "1 |?|?|\n"
									  "   - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);
	_consoleBoard->cells().value(0).value(0, NULL)->setHasBomb(true);
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);

	QCOMPARE(_consoleBoard->makeTurn(0,0,false), kSBombed);

	boardStringRepresentation = ("   a b\n"
								 "   - -\n"
								 "0 |*| |\n"
								 "   - -\n"
								 "1 | | |\n"
								 "   - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);
}

void ConsoleUITest::testBoardDisplayingWin()
{
	_consoleBoard->cells().value(0).value(0, NULL)->setHasBomb(true);
	QCOMPARE(_consoleBoard->makeTurn(0,0,true), kSWinned);

	QString boardStringRepresentation("   a b\n"
								 "   - -\n"
								 "0 |F| |\n"
								 "   - -\n"
								 "1 | | |\n"
								 "   - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);
}

void ConsoleUITest::testBoardDisplayingMissedFlag()
{
	_consoleBoard->cells().value(0).value(0, NULL)->setHasBomb(true);
	QCOMPARE(_consoleBoard->makeTurn(0,1,true), kSContinue);

	QString boardStringRepresentation("   a b\n"
								 "   - -\n"
								 "0 |?|F|\n"
								 "   - -\n"
								 "1 |?|?|\n"
								 "   - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);

	QCOMPARE(_consoleBoard->makeTurn(0,0,false), kSBombed);

	boardStringRepresentation = ("   a b\n"
								 "   - -\n"
								 "0 |*|-|\n"
								 "   - -\n"
								 "1 | | |\n"
								 "   - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);
}

void ConsoleUITest::testBoardDisplayingNumberOfBombs()
{
	QString boardStringRepresentation("   a b\n"
									  "   - -\n"
									  "0 |?|?|\n"
									  "   - -\n"
									  "1 |?|?|\n"
									  "   - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);
	_consoleBoard->cells().value(0).value(0, NULL)->setHasBomb(true);
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);

	QCOMPARE(_consoleBoard->makeTurn(0,1,false), kSContinue);
	boardStringRepresentation = ("   a b\n"
								 "   - -\n"
								 "0 |?|1|\n"
								 "   - -\n"
								 "1 |?|?|\n"
								 "   - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);

	_consoleBoard->setSize(3,3);
	boardStringRepresentation = ("   a b c\n"
								 "   - - -\n"
								 "0 |?|?|?|\n"
								 "   - - -\n"
								 "1 |?|?|?|\n"
								 "   - - -\n"
								 "2 |?|?|?|\n"
								 "   - - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);
	_consoleBoard->cells().value(0).value(0, NULL)->setHasBomb(true);
	_consoleBoard->cells().value(1).value(0, NULL)->setHasBomb(true);
	_consoleBoard->cells().value(2).value(0, NULL)->setHasBomb(true);
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);

//	QCOMPARE(_consoleBoard->makeTurn(1,2,false), kSContinue);
	QCOMPARE(_consoleBoard->makeTurn("c1"), kSContinue);
	boardStringRepresentation = ("   a b c\n"
								 "   - - -\n"
								 "0 |?|2| |\n"
								 "   - - -\n"
								 "1 |?|3| |\n"
								 "   - - -\n"
								 "2 |?|2| |\n"
								 "   - - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);

	_consoleBoard->setSize(5,5);
	_consoleBoard->cells().value(4).value(4, NULL)->setHasBomb(true);

	boardStringRepresentation = ("   a b c d e\n"
								 "   - - - - -\n"
								 "0 |?|?|?|?|?|\n"
								 "   - - - - -\n"
								 "1 |?|?|?|?|?|\n"
								 "   - - - - -\n"
								 "2 |?|?|?|?|?|\n"
								 "   - - - - -\n"
								 "3 |?|?|?|?|?|\n"
								 "   - - - - -\n"
								 "4 |?|?|?|?|?|\n"
								 "   - - - - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);

	QCOMPARE(_consoleBoard->makeTurn("a0"), kSContinue);
	boardStringRepresentation = ("   a b c d e\n"
								 "   - - - - -\n"
								 "0 | | | | | |\n"
								 "   - - - - -\n"
								 "1 | | | | | |\n"
								 "   - - - - -\n"
								 "2 | | | | | |\n"
								 "   - - - - -\n"
								 "3 | | | |1|1|\n"
								 "   - - - - -\n"
								 "4 | | | |1|?|\n"
								 "   - - - - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);

}

void ConsoleUITest::testConsoleMakeTurn()
{
	QString boardStringRepresentation("   a b\n"
									  "   - -\n"
									  "0 |?|?|\n"
									  "   - -\n"
									  "1 |?|?|\n"
									  "   - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);
	_consoleBoard->cells().value(0).value(0, NULL)->setHasBomb(true);
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);

	QCOMPARE(_consoleBoard->makeTurn("b0"), kSContinue);
	boardStringRepresentation = ("   a b\n"
								 "   - -\n"
								 "0 |?|1|\n"
								 "   - -\n"
								 "1 |?|?|\n"
								 "   - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);

	QCOMPARE(_consoleBoard->makeTurn("b1f"), kSContinue);
	boardStringRepresentation = ("   a b\n"
								 "   - -\n"
								 "0 |?|1|\n"
								 "   - -\n"
								 "1 |?|F|\n"
								 "   - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);

	QCOMPARE(_consoleBoard->makeTurn("a0"), kSBombed);
	boardStringRepresentation = ("   a b\n"
								 "   - -\n"
								 "0 |*|1|\n"
								 "   - -\n"
								 "1 | |-|\n"
								 "   - -\n");
	QCOMPARE(_consoleBoard->stringRepresentation(),
		boardStringRepresentation);

}

void ConsoleUITest::cleanup()
{
	delete _consoleBoard;
}
