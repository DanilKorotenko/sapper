#include <qapplication.h>
#include <saper.h>

int main(int argc, char **argv)
{
	QApplication app(argc,argv);
	Saper minesweeper(0);
//	app.setMainWidget(&minesweeper);
//	app.set
	minesweeper.show();
	return app.exec();
}
