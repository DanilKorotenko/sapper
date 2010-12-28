#ifndef TERMINALUITEST_H
#define TERMINALUITEST_H

#include <QObject>
#include <QPointer>

class STerminalBoard;

class TerminalUITest : public QObject
{
	Q_OBJECT
private:
	QPointer<STerminalBoard> _terminalBoard;

private slots:
	void init();

	void testBoardDisplaying();

	void cleanup();

};

#endif // TERMINALUITEST_H
