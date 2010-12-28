#include "SConsoleGame.h"

#include "SConsoleBoard.h"

#include <iostream>


SConsoleGame::SConsoleGame(QObject *parent) : QObject(parent)
{
}

void SConsoleGame::execute()
{
	std::cout<<"1. play new game" << std::endl;
	std::cout << std::endl;

	std::cout<<"woul'd you like to do?" << std::endl;
	std::cout<<"enter a number of your choise:" << std::endl;
	char ch = 0;
	std::cin >> ch;
	switch(ch)
	{
		case '1':
		{
			this->playGame();
			break;
		}
		default:
		{
			break;
		}
	};
}

void SConsoleGame::playGame()
{
	SConsoleBoard board(10,10);
	std::cout << board.stringRepresentation().toAscii().constData();
}
