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
	std::cout << "Hello console saper\n";

	SConsoleGame game;
	game.execute();

	QTimer::singleShot(1000, &app, SLOT(quit())); //stop after 5 seconds

	return app.exec();
}
