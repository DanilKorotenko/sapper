#include <QtTest/QtTest>

#include <QPointer>

#include "sboard.h"

class DataModelTest: public QObject
{
	Q_OBJECT
private:
	QPointer<SBoard> _board;

private slots:
	void init();

	void testBoardCreation();
	void testMarkUnMark();
	void testCheckVictory();
	void testMakeWinnerTurn();
	void testGameOverTurn();
	void testCellsChecking();

	void cleanup();
};

