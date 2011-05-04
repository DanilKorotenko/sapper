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

bool SaperButton::checked()
{
	return _checked;
}

void SaperButton::setIsChecked(bool value)
{
	_checked = value;
}

void SaperButton::setNumberOfBobs(qint8 value)
{
	_numberOfBombs = value;
	if (0 == _numberOfBombs)
	{
		this->hide();
	}
	else
	{
		this->setText(QString("%1").arg(_numberOfBombs));
	}
}

