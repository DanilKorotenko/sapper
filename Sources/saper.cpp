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

#include "saper.h"

#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <QPushButton>
#include <QPixmap>
#include <QMouseEvent>
#include <windows.h>
#include <qevent.h>
#include <qmenubar.h>
#include <QMenu>
#include <QLCDNumber>
#include <QGridLayout>

#include "cell.h"

Saper::Saper(QWidget *parent) : QWidget(parent)
{
	int i,j;
	n=20; m=20;
	n_bombs=70;
	clearFocus();

	top = new QGridLayout(this);
	ind = new QLCDNumber(this);
	top->addWidget(ind,0,0,1,3);
	top->setHorizontalSpacing(0);
	top->setVerticalSpacing(0);
	ind->setSegmentStyle(QLCDNumber::Flat);
	buttons = new saper_buttons(col());
	mnu = new QMenuBar(this);

	pmnu = mnu->addMenu(tr("Game"));

	pmnu->addAction(tr("New Game"),this,SLOT(newgame()),Qt::Key_F2);
	pmnu->addSeparator();
	pmnu->addAction(tr("Easy"),this,SLOT(newgame()));
	pmnu->addAction(tr("Medium"),this,SLOT(newgame()));
	pmnu->addAction(tr("Hard"),this,SLOT(newgame()));
	pmnu->addSeparator();
	pmnu->addAction(tr("Exit"),this,SLOT(close()),Qt::Key_Escape);

	pole = new Cell*[n];
	for (i=0;i<n;i++)
	{
		pole[i] = new Cell[m];
	}

	QPushButton *cmd1;
	int i_col=0;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			pole[i][j].setGamePole(this);
			cmd1 = pole[i][j].button();
			top->addWidget(cmd1,i+2,j);
			buttons->insert(i_col,cmd1);
			i_col++;
		}
	}
	newgame();
}

void Saper::slotButtonClicked()
{
	int x,y;
	int i;

	QPixmap pix("images/red_bomb.bmp");
	i = buttons->indexOf((QPushButton*)sender());

	QPushButton *cmd1;
	y = i % n;
	x = i / m;

	if(!pole[x][y].val)
	{
		check(x,y);
	}
	else
	{
		cmd1 = buttons->at(i);
		cmd1->setIcon(QIcon(pix));
		for (i=0;i!=col();i++)
		{
			y=i%n;
			x=i/m;
			cmd1 = buttons->at(i);
			if(pole[x][y].val)
			{
				cmd1->setIcon(QIcon(pix));
			}
		}

		for (i=0;i!=col();i++)
		{
			cmd1 = buttons->at(i);
			cmd1->disconnect();
		}
	}
}

void Saper::check(int x,int y)
{
	int col=n*m;
	int i,k,l;
	int nn_bombs=0;
	i = x * n + y;
	if (((i < col) && (i >= 0)) && (( x < n) && (x >= 0) && (y < m) && (y >= 0))
		&& (!pole[x][y].val) && (!pole[x][y].checked))
	{
		pole[x][y].checked = true;
		cells_checked--;
		if (cells_checked==0)
		{
			MessageBox(NULL,L"Congradulations!",NULL,MB_OK);
			newgame();
		}

		QPushButton *cmd1 = buttons->at(i);

		for ( k = x - 1; k < x + 2; k++)
		{
			for (l = y - 1; l < y + 2; l++)
			{
				if (((k < n)&&(k >= 0)&&(l < m)&&(l >= 0)) &&
					(pole[k][l].val == true))
				{
					nn_bombs++;
				}
			}
		}

		if (nn_bombs==0)
		{
			cmd1->hide();
			for (k = x - 1; k < x + 2; k++)
			{
				for(l = y - 1; l < y + 2; l++)
				{
					check(k,l);
				}
			}
		}
		else
		{
			switch (nn_bombs)
			{
				case 1:
				{
					QPixmap pix("images/one.bmp");
					cmd1->setIcon(QIcon(pix));
					break;
				}
				case 2:
				{
					QPixmap pix("images/two.bmp");
					cmd1->setIcon(QIcon(pix));
					break;
				}
				case 3:
				{
					QPixmap pix("images/three.bmp");
					cmd1->setIcon(QIcon(pix));
					break;
				}
				case 4:
				{
					QPixmap pix("images/four.bmp");
					cmd1->setIcon(QIcon(pix));
					break;
				}
				case 5:
				{
					QPixmap pix("images/five.bmp");
					cmd1->setIcon(QIcon(pix));
					break;
				}
				case 6:
				{
					QPixmap pix("images/six.bmp");
					cmd1->setIcon(QIcon(pix));
					break;
				}
				case 7:
				{
					QPixmap pix("images/seven.bmp");
					cmd1->setIcon(QIcon(pix));
					break;
				}
				case 8:
				{
					QPixmap pix("images/eight.bmp");
					cmd1->setIcon(QIcon(pix));
					break;
				}
			}
		}
	}
}

void Saper::newgame()
{
	int x = 0;
	int y = 0;
	setFixedSize(n * 17 + 5,m * 17 + 5 + 50);
	bombs = n_bombs;
	ind->display(bombs);
	cells_checked = col();
	QPushButton *cmd1;
	for (int i = 0; i != col(); i++)
	{
		y = i % n;
		x = i / m;
		cmd1 = buttons->at(i);
		cmd1->show();
		cmd1->setText("");
		cmd1->setDown(false);
		connect(cmd1,SIGNAL(clicked()),SLOT(slotButtonClicked()));
	}
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			pole[i][j].x = i;
			pole[i][j].y = j;
			pole[i][j].checked = false;
			pole[i][j].val = false;
		}
	}
	srand(time(NULL));
	for (int i = 0; i < n_bombs; )
	{
		x = rand() % n;
		y = rand() % m;
		if (!(pole[x][y].val))
		{
			pole[x][y].val = true;
			i++;
		}
	}
}

void Saper::mousePressEvent(QMouseEvent *e)
{
	int x,y;
	QPushButton *cmd1;
	QPixmap pix("images/flag.bmp");
	if (Qt::RightButton == e->button())
	{
		for (int i = 0; i != col(); i++)
		{
			y = i % n;
			x = i / m;
			cmd1 = buttons->at(i);
			if (cmd1->testAttribute(Qt::WA_UnderMouse))
			{
				if ((pole[x][y].val) && (!pole[x][y].checked))
				{
					pole[x][y].checked = true;
					cells_checked--;
					bombs--;
					ind->display(bombs);
				}
				if (cells_checked==0)
				{
					MessageBox(NULL,L"Congradulations!",NULL,MB_OK);
					newgame();
				}
				if ((cmd1->icon()).isNull())
				{
					cmd1->setIcon(QIcon(pix));
				}
				else if (!pole[x][y].val)
				{
					cells_checked++;
					cmd1->setText("");
				}
			}
		}
	}
/*	else if (e->button()==QMouseEvent::MidButton)
	{
		int k,l;
		for (i=0;i!=col();i++)
		{
			y=i%n;
			x=i/m;
			cmd1 = buttons->at(i);
			if (cmd1->hasMouse())
			{
				if (pole[x][y].checked)
				{
				for (k=x-1;k<x+2;k++)
					for(l=y-1;l<y+2;l++)
					{
						if ((k<n)&&(k>=0)&&(l<m)&&(l>=0))
						if (!pole[k][l].checked)
						{
							i=k*n+l;
							cmd1 = buttons->at(i);
							cmd1->setDown(true);
						}
					}
				}
			}
		}
	}*/
}
