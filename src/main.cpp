#include <QApplication>
//#include "saper.h"
#include "saperboard.h"

int main(int argc, char **argv)
{
	QApplication app(argc,argv);
//	Saper minesweeper(0);

//	app.setMainWidget(&minesweeper);
//	app.set
//	minesweeper.show();

	SaperBoard board(QSize(10,10), 10);
	board.show();

	return app.exec();
}
