#ifndef SGUICELL_H
#define SGUICELL_H

#include "dataModel/scell.h"

class SGUICell : public SCell
{
	Q_OBJECT
public:
	explicit SGUICell(QObject *parent = 0);

	bool isGameOver();
	void setGameOver(bool flag);

//parent methods
	void toggleFlag();
	void setNumberOfBombsArround(quint8 value);

signals:
	void stateChanged();

private:
	bool _gameOver;

};

#endif // SGUICELL_H
