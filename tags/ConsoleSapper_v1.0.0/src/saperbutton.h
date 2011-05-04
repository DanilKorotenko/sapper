#ifndef SAPERBUTTON_H
#define SAPERBUTTON_H

#include <QPushButton>

class SaperButton : public QPushButton
{
	Q_OBJECT
public:
	SaperButton(QWidget *parent = 0);

	bool hasBomb();
	void setHasBomb(bool value);

	bool checked();
	void setIsChecked(bool value);

	void setNumberOfBobs(qint8 value);

private:
	bool _hasBomb;
	bool _checked;
	qint8 _numberOfBombs;

};

#endif // SAPERBUTTON_H
