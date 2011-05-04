#ifndef SCONSOLEGAME_H
#define SCONSOLEGAME_H

#include <QObject>

class SConsoleGame : public QObject
{
	Q_OBJECT
public:
	explicit SConsoleGame(QObject *parent = 0);

	void execute();

private:
	void playGame();

};

#endif // SCONSOLEGAME_H
