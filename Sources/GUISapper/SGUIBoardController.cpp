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

#include "SGUIBoardController.h"

#include <QGridLayout>
#include <QButtonGroup>

#include "SGUIBoard.h"
#include "SGUIButton.h"

SGUIBoardController::SGUIBoardController(QWidget *parent) : QWidget(parent)
{
	_gameBoard = new SGUIBoard(this);

	QGridLayout *topLayout = new QGridLayout(this);

	QSize size;
	size.setWidth(5);
	size.setHeight(5);

	for (qint8 indexX = 0; indexX < size.width(); indexX++)
	{
		for (qint8 indexY = 0; indexY < size.height(); indexY++)
		{
			topLayout->addWidget(new SGUIButton(this),indexX,indexY);
		}
	}

	topLayout->setHorizontalSpacing(0);
	topLayout->setVerticalSpacing(0);
	this->setLayout(topLayout);
}

void SGUIBoardController::slotNewGame()
{

}
