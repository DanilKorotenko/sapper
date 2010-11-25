#include "scell.h"

SCell::SCell(QObject *parent) :
	 QObject(parent)
{
}

bool SCell::hasBomb()
{
	return _hasBomb;
}

void SCell::setHasBomb(bool value)
{
	_hasBomb = value;
}

bool SCell::checked()
{
	return _checked;
}

void SCell::setChecked(bool value)
{
	_checked = value;
}

qint8 SCell::numberOfBombsArround()
{
	return _numberOfBombsArround;
}

void SCell::setNumberOfBombsArround(qint8 value)
{
	_numberOfBombsArround = value;
}

