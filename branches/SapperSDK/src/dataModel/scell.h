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

#ifndef SCELL_H
#define SCELL_H

#include <QObject>

class SCell : public QObject
{
	Q_OBJECT
public:
	explicit SCell(QObject *parent = 0);

	bool hasBomb();
	void setHasBomb(bool value);

	bool checked();
	void setChecked(bool value);

	bool flagged();
	void toggleFlag();

	uint numberOfBombs();
	void setNumberOfBombsArround(uint value);

private:
	bool _hasBomb;
	bool _checked;
	bool _flagged;
	uint _numberOfBombs;

};

#endif // SCELL_H
