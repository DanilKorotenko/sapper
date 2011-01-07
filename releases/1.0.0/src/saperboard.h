#ifndef SAPERBOARD_H
#define SAPERBOARD_H

#include <QWidget>
#include <QSize>

class QButtonGroup;
class QGridLayout;
class QPushButton;
class QAbstractButton;

class SaperButton;

class SaperBoard : public QWidget
{
	Q_OBJECT
public:
	SaperBoard(QSize size, qint8 numberOfBombs, QWidget *parent = 0);
	~SaperBoard();

protected:
	void keyPressEvent(QKeyEvent *event);

private slots:
	void buttonClicked(QAbstractButton* button);
	void reset();

private: //Methods
	void checkCell(qint8 indexX, qint8 indexY);

private: //Data
	QGridLayout *_topLayout;
	QButtonGroup *_buttons;
	QSize _size;
	qint8 _numberOfBombs;

};

#endif // SAPERBOARD_H
