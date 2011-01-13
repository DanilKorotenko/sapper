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


SConsoleGame::SConsoleGame(QObject *parent) : QObject(parent)
{
}

void SConsoleGame::execute()
{
	printLicense();

//	std::cout<<"1. play new game" << std::endl;
	std::cout << std::endl;

//	std::cout<<"woul'd you like to do?" << std::endl;
//	std::cout<<"enter a number of your choise:" << std::endl;
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
		std::cout << board.stringRepresentation().toAscii().constData()
			<< std::endl;
		char playerTurn[6];
		std::cin >> playerTurn;
		QString turn = QString(playerTurn);
		if (QString("show w") == turn)
		{
			printWarranties();
		}
		else if (QString("show c") == turn)
		{
			printConditions();
		}
		else
		{
			gameCondition = board.makeTurn(QString(playerTurn));
		}
	}
	std::cout << board.stringRepresentation().toAscii().constData()
		<< std::endl;
	if (kSWinned == gameCondition)
	{
		std::cout << "You are winned! :)" << std::endl;
	}
	else if (kSBombed == gameCondition)
	{
		std::cout << "You are bombed. :(" << std::endl;
	}
}

void SConsoleGame::printLicense()
{
	std::cout << "ConsoleSapper version 1.0.0." << std::endl;
	std::cout << "Copyright (C) 2011 Korotenko Danil" << std::endl;
	std::cout << std::endl;
	std::cout << "ConsoleSapper comes with ABSOLUTELY NO WARRANTY;" << std::endl;
	std::cout << "This is free software, and you are welcome to redistribute it" << std::endl;
	std::cout << "under certain conditions;" << std::endl;
}

void SConsoleGame::printWarranties()
{

}

void SConsoleGame::printConditions()
{

}
