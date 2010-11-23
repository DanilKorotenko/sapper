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

private:
	bool _hasBomb;

};

#endif // SAPERBUTTON_H
