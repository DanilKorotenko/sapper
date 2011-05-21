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

#include "SConsoleGame.h"

#include "SConsoleBoard.h"

#include <iostream>

#include <QFile>

SConsoleGame::SConsoleGame(QObject *parent) :
	QObject(parent),
	_inStream(stdin),
	_outStream(stdout)
{
}

void SConsoleGame::execute()
{
	printLicense();

//	_outStream <<"1. play new game" << endl;

	_outStream << endl;

	printInstructions();

	_outStream << endl;

//	_outStream <<"woul'd you like to do?" << endl;
//	_outStream <<"enter a number of your choise:" << endl;
//	char ch = 0;
//	std::cin >> ch;
//	switch(ch)
//	{
//		case '1':
//		{
			this->playGame();
//			break;
//		}
//		default:
//		{
//			break;
//		}
//	};
}

void SConsoleGame::playGame()
{
	SGameCondition gameCondition = kSContinue;

	SConsoleBoard board(5,5);
	board.placeBombs(5);
	while(kSContinue == gameCondition)
	{
		_outStream << board.stringRepresentation() << endl;
		QString playerTurn = _inStream.readLine();
		if (QString("show w") == playerTurn)
		{
			printWarranties();
		}
		else if (QString("show c") == playerTurn)
		{
			printConditions();
		}
		else if (QString("q") == playerTurn)
		{
			break;
		}
		else
		{
			gameCondition = board.makeTurn(playerTurn);
		}
	}
	_outStream << board.stringRepresentation() << endl;
	if (kSWinned == gameCondition)
	{
		_outStream << "You are winned! :)" << endl;
	}
	else if (kSBombed == gameCondition)
	{
		_outStream << "You are bombed. :(" << endl;
	}
}

void SConsoleGame::printInstructions()
{
	_outStream << "type 'q' to exit." << endl;

}

void SConsoleGame::printLicense()
{
	_outStream << "ConsoleSapper version 1.0.0." << endl;
	_outStream << "Copyright (C) 2011 Korotenko Danil" << endl;
	_outStream << endl;
	_outStream << "ConsoleSapper comes with ABSOLUTELY NO WARRANTY; for details type `show w'." << endl;
	_outStream << "This is free software, and you are welcome to redistribute it" << endl;
	_outStream << "under certain conditions; type `show c' for details." << endl;
}

void SConsoleGame::printWarranties()
{
	QFile file(":/license/warranties.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return;
	}

	_outStream << file.readAll();
}

void SConsoleGame::printConditions()
{
	QFile file(":/license/copying.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return;
	}

	_outStream << file.readAll();
}
