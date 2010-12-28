#include <QCoreApplication>

#include <QTimer>
#include <QTextStream>
#include <QDebug>

#include <iostream>

#include "SConsoleGame.h"

int main(int argc, char **argv)
{
	QCoreApplication app(argc, argv);

	std::cout << "Hello console saper\n";

	SConsoleGame game;
	game.execute();

	QTimer::singleShot(1000, &app, SLOT(quit())); //stop after 5 seconds

	return app.exec();
}
