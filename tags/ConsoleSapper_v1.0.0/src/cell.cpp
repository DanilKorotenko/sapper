#include "cell.h"

#include <QPushButton>
#include "saper.h"

Cell::Cell(QObject *parent) : QObject(parent)
{
	_button = this->createButton();
}

Cell::~Cell()
{
	delete _button;
}

void Cell::setGamePole(Saper *value)
{
	_gamePole = value;
	connect(_button,SIGNAL(clicked()), _gamePole, SLOT(slotButtonClicked()));
}

QPushButton *Cell::button()
{
	return _button;
}

QPushButton *Cell::createButton()
{
	QPushButton *cmd = new QPushButton();
	cmd->setMaximumSize(17,17);
	cmd->clearFocus();
	return cmd;
}
