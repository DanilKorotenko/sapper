#include "SGUICell.h"

SGUICell::SGUICell(QObject *parent) : SCell(parent)
{
}

bool SGUICell::isGameOver()
{
	return _gameOver;
}

void SGUICell::setGameOver(bool flag)
{
	_gameOver = flag;
	emit stateChanged();
}

void SGUICell::toggleFlag()
{
	SCell::toggleFlag();
	emit stateChanged();
}

void SGUICell::setNumberOfBombsArround(quint8 value)
{
	SCell::setNumberOfBombsArround(value);
	emit stateChanged();
}

