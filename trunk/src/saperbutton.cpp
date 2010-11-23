#include "saperbutton.h"

SaperButton::SaperButton(QWidget *parent) : QPushButton(parent)
{
	_hasBomb = false;
}

bool SaperButton::hasBomb()
{
	return _hasBomb;
}

void SaperButton::setHasBomb(bool value)
{
	_hasBomb = value;
	if (_hasBomb)
	{
		this->setText("*");
	}
	else
	{
		this->setText("");
	}
}
