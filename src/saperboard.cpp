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

#include "saperboard.h"
#include "saperbutton.h"

#include <QButtonGroup>
#include <QGridLayout>
#include <QDateTime>
#include <QKeyEvent>
#include <QMessageBox>

SaperBoard::SaperBoard(QSize size, qint8 numberOfBombs, QWidget *parent) :
	QWidget(parent), _size(size), _numberOfBombs(numberOfBombs)
{
	_topLayout = new QGridLayout();
	_buttons = new QButtonGroup(this);
	connect(_buttons, SIGNAL(buttonClicked(QAbstractButton*)), this,
		SLOT(buttonClicked(QAbstractButton*)));

	qint8 buttonIndex = 0;
	for (qint8 indexX = 0; indexX < _size.width(); indexX++)
	{
		for (qint8 indexY = 0; indexY < _size.height(); indexY++)
		{
			SaperButton *button = new SaperButton(this);
			_buttons->addButton(button, buttonIndex);
			buttonIndex++;
			_topLayout->addWidget(button,indexX,indexY);
		}
	}
	_topLayout->setHorizontalSpacing(0);
	_topLayout->setVerticalSpacing(0);;
	this->setLayout(_topLayout);

	this->reset();
}

SaperBoard::~SaperBoard()
{
	delete _buttons;
	delete _topLayout;

}

void SaperBoard::keyPressEvent(QKeyEvent *event)
{
	if (Qt::Key_Escape == event->key())
	{
		this->close();
	}
	if (Qt::Key_F5 == event->key())
	{
		this->reset();
	}
}

void SaperBoard::reset()
{
	// reset bombs
	quint8 numberOfButtons = _size.width() * _size.height();
	for (quint8 index = 0; index < numberOfButtons; index++)
	{
		((SaperButton *)_buttons->button(index))->setHasBomb(false);
	}
	qsrand(QDateTime::currentDateTime().toTime_t());
	for (quint8 indexOfBomb = 0; indexOfBomb < _numberOfBombs; )
	{
		quint8 indexOfButton = qrand() % numberOfButtons;
		SaperButton *button = (SaperButton *)_buttons->button(indexOfButton);

		if (!(button->hasBomb()))
		{
			button->setHasBomb(true);
			indexOfBomb++;
		}
	}
}

void SaperBoard::buttonClicked(QAbstractButton *button)
{
	SaperButton *saperButton = (SaperButton *)button;

	if (saperButton->hasBomb())
	{
		QMessageBox::information(this, tr("Game over"), tr("The game is over."),
			QMessageBox::Ok);
	}
	else
	{

	}
}

void SaperBoard::checkCell(qint8 indexX, qint8 indexY)
{

}
