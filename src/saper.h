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

#ifndef _saper_h_
#define _saper_h_

#include <QWidget>
#include <QVector>
#include <QMouseEvent>

class QPushButton;
class QGridLayout;
class QMouseEvent;
class QMenuBar;
class QMenu;
class QLCDNumber;

class Cell;

typedef QVector<QPushButton *> saper_buttons;

class Saper : public QWidget
{
	Q_OBJECT
public:
	Saper(QWidget *parent=0);

protected:
	void mousePressEvent(QMouseEvent *e);

private:
	int n,m;
	Cell **pole;
	int n_bombs,bombs;
	int cells_checked;
	saper_buttons *buttons;
	QGridLayout* top;
	QMenuBar *mnu;
	QMenu *pmnu;
	QLCDNumber *ind;

	void check(int x,int y);

	int col(){return n*m;}

private slots:
	void slotButtonClicked();
	void newgame();

};

#endif
