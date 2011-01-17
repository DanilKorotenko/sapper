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

#ifndef SGUICELL_H
#define SGUICELL_H

#include "dataModel/scell.h"

class SGUICell : public SCell
{
	Q_OBJECT
public:
	explicit SGUICell(QObject *parent = 0);

	bool isGameOver();
	void setGameOver(bool flag);

//parent methods
	void toggleFlag();
	void setNumberOfBombsArround(quint8 value);

signals:
	void stateChanged();

private:
	bool _gameOver;

};

#endif // SGUICELL_H
