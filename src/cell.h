#ifndef CELL_H
#define CELL_H

#include <QObject>

class QPushButton;

class Saper;

class Cell : public QObject
{
	Q_OBJECT
public:
	Cell(QObject *parent = 0);
	~Cell();

	void setGamePole(Saper *value);

	bool val,checked;
	int x,y;

	QPushButton *button();

private:
	Saper *_gamePole;
	QPushButton *_button;

	QPushButton *createButton();

};

#endif // CELL_H
