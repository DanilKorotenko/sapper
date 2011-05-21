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

#include "SConsoleCell.h"

SConsoleCell::SConsoleCell(QObject *parent) : SCell(parent)
{
}

QString SConsoleCell::stringRepresentation(bool gameOver)
{
	QString result;

	if (checked())
	{
		if (0 == numberOfBombs())
		{
			result = " ";
		}
		else
		{
			result.append(QString("%1").arg(numberOfBombs()));
		}
	}
	else if (gameOver)
	{
		if (flagged())
		{
			if (hasBomb())
			{
				result = "F";
			}
			else
			{
				result = "-";
			}
		}
		else if (hasBomb())
		{
			result = "*";
		}
		else
		{
			result = " ";
		}
	}
	else if (flagged())
	{
		result = "F";
	}
	else
	{
		result = "?";
	}

	return result;
}
