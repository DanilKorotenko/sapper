#ifndef CONSOLEUITEST_H
#define CONSOLEUITEST_H

#include <QObject>
#include <QPointer>

class SConsoleBoard;

class ConsoleUITest : public QObject
{
	Q_OBJECT
private:
	QPointer<SConsoleBoard> _consoleBoard;

private slots:
	void init();

	void testBoardDisplaying();

	void cleanup();

};

#endif // CONSOLEUITEST_H
