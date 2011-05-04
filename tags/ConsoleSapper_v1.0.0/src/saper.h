#ifndef _saper_h_
#define _saper_h_

#include <QWidget>
#include <QVector>
#include <QMouseEvent>

class QPushButton;
class QGridLayout;
class QMouseEvent;
class QMenuBar;
class QMenu;
class QLCDNumber;

class Cell;

typedef QVector<QPushButton *> saper_buttons;

class Saper : public QWidget
{
	Q_OBJECT
public:
	Saper(QWidget *parent=0);

protected:
	void mousePressEvent(QMouseEvent *e);

private:
	int n,m;
	Cell **pole;
	int n_bombs,bombs;
	int cells_checked;
	saper_buttons *buttons;
	QGridLayout* top;
	QMenuBar *mnu;
	QMenu *pmnu;
	QLCDNumber *ind;

	void check(int x,int y);

	int col(){return n*m;}

private slots:
	void slotButtonClicked();
	void newgame();

};

#endif
