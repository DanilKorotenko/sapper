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

#include "saperbutton.h"

SaperButton::SaperButton(QWidget *parent) : QPushButton(parent)
{
	_hasBomb = false;
}

bool SaperButton::hasBomb()
{
	return _hasBomb;
}

void SaperButton::setHasBomb(bool value)
{
	_hasBomb = value;
	if (_hasBomb)
	{
		this->setText("*");
	}
	else
	{
		this->setText("");
	}
}

bool SaperButton::checked()
{
	return _checked;
}

void SaperButton::setIsChecked(bool value)
{
	_checked = value;
}

void SaperButton::setNumberOfBobs(qint8 value)
{
	_numberOfBombs = value;
	if (0 == _numberOfBombs)
	{
		this->hide();
	}
	else
	{
		this->setText(QString("%1").arg(_numberOfBombs));
	}
}

