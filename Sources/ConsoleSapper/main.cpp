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

#include <QCoreApplication>

#include <QTimer>
#include <QTextStream>
#include <QDebug>

#include <iostream>

#include "SConsoleGame.h"

int main(int argc, char **argv)
{
	QCoreApplication app(argc, argv);

	app.setApplicationName("ConsolaSaper");
	app.setOrganizationName("DanilKorotenko");
	app.setApplicationVersion("1.0.0");

	SConsoleGame game;
	game.execute();

	QTimer::singleShot(1000, &app, SLOT(quit())); //stop after 5 seconds

	return app.exec();
}
