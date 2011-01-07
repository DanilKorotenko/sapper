#include "SConsoleGame.h"

#include "SConsoleBoard.h"

#include <iostream>


SConsoleGame::SConsoleGame(QObject *parent) : QObject(parent)
{
}

void SConsoleGame::execute()
{
//	std::cout<<"1. play new game" << std::endl;
//	std::cout << std::endl;

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
		char playerTurn[3];
		std::cin >> playerTurn;
		gameCondition = board.makeTurn(QString(playerTurn));
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
