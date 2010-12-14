#include "scell.h"

SCell::SCell(QObject *parent) :
	 QObject(parent)
{
	_hasBomb = false;
	_checked = false;
	_flagged = false;
	_numberOfBombsArround = 0;
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

bool SCell::flagged()
{
	return _flagged;
}

void SCell::toggleFlag()
{
	_flagged = !_flagged;
}

qint8 SCell::numberOfBombsArround()
{
	return _numberOfBombsArround;
}

void SCell::setNumberOfBombsArround(qint8 value)
{
	_numberOfBombsArround = value;
}

