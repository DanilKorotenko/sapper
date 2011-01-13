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

#ifndef SAPERBOARD_H
#define SAPERBOARD_H

#include <QWidget>
#include <QSize>

class QButtonGroup;
class QGridLayout;
class QPushButton;
class QAbstractButton;

class SaperButton;

class SaperBoard : public QWidget
{
	Q_OBJECT
public:
	SaperBoard(QSize size, qint8 numberOfBombs, QWidget *parent = 0);
	~SaperBoard();

protected:
	void keyPressEvent(QKeyEvent *event);

private slots:
	void buttonClicked(QAbstractButton* button);
	void reset();

private: //Methods
	void checkCell(qint8 indexX, qint8 indexY);

private: //Data
	QGridLayout *_topLayout;
	QButtonGroup *_buttons;
	QSize _size;
	qint8 _numberOfBombs;

};

#endif // SAPERBOARD_H
