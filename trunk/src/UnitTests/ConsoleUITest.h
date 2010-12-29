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
	void testBigBoardDisplaying();
	void testBoardInGameDisplayingGameOver();
	void testBoardInGameDisplayingWin();

	void cleanup();

};

#endif // CONSOLEUITEST_H
