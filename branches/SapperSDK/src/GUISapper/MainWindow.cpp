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

#include "MainWindow.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QKeySequence>
#include <QMessageBox>
#include <QFile>

#include "SGUIBoardController.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	this->createAndAddActions();

	_boardController = new SGUIBoardController(this);
	this->setCentralWidget(_boardController);
}

MainWindow::~MainWindow()
{

}

void MainWindow::createAndAddActions()
{
// File menu
	QMenu *fileMenu = menuBar()->addMenu(tr("File"));
	fileMenu->addAction(tr("New Game"), this, SLOT(slotNewGame()),
		QKeySequence(QKeySequence::New));
	fileMenu->addAction(tr("Exit"), qApp, SLOT(quit()),
		QKeySequence(Qt::Key_Escape));

//Help menu
	QMenu *helpMenu = menuBar()->addMenu(tr("Help"));
	helpMenu->addSeparator();
	helpMenu->addAction(tr("Show warranties"), this,
		SLOT(slotShowWarranties()));
	helpMenu->addAction(tr("Show copying"), this, SLOT(slotShowCopying()));
	helpMenu->addSeparator();
	helpMenu->addAction(tr("About Qt..."), qApp, SLOT(aboutQt()));
	helpMenu->addAction(tr("About GUISapper..."), this, SLOT(slotAbout()));
}

void MainWindow::slotNewGame()
{
	_boardController->slotNewGame();
}

void MainWindow::slotShowWarranties()
{
	QFile file(":/license/warranties.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return;
	}

	QByteArray fileContent = file.readAll();
	QMessageBox::information(this,qApp->applicationName(),QString(fileContent),
		QMessageBox::Ok);
}

void MainWindow::slotShowCopying()
{
	QFile file(":/license/copying.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return;
	}

	QByteArray fileContent = file.readAll();
	QMessageBox::information(this,qApp->applicationName(),QString(fileContent),
		QMessageBox::Ok);
}

void MainWindow::slotAbout()
{
	QMessageBox::about(this, qApp->applicationName(),
		QString("%1 version %2.\n"
				"Copyright (C) 2011 Korotenko Danil\n\n"
				"%3 comes with ABSOLUTELY NO WARRANTY; for details choose `Help -> show warranties...'.\n"
				"This is free software, and you are welcome to redistribute it\n"
				"under certain conditions; choose `Help -> show copying...' for details.")
				.arg(qApp->applicationName()).arg(qApp->applicationVersion())
				.arg(qApp->applicationName()));
}
