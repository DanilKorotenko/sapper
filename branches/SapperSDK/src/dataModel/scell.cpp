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

#include "scell.h"

SCell::SCell()
{
	_hasBomb = false;
	_checked = false;
	_flagged = false;
	_numberOfBombs = 0;
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

unsigned int SCell::numberOfBombs()
{
	return _numberOfBombs;
}

void SCell::setNumberOfBombsArround(unsigned int value)
{
	_numberOfBombs = value;
}
