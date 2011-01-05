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
	void testBoardDisplayingGameOver();
	void testBoardDisplayingWin();
	void testBoardDisplayingMissedFlag();
	void testBoardDisplayingNumberOfBombs();

	void cleanup();

};

#endif // CONSOLEUITEST_H
