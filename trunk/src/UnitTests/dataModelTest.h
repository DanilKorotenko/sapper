#include <QtTest/QtTest>

#include <QPointer>

#include "dataModel/sboard.h"

class DataModelTest: public QObject
{
	Q_OBJECT
private:
	QPointer<SBoard> _board;

//Additional methods for internal use.
	void verifyInitialState();

private slots:
	void init();

	void testBoardCreation();
	void testBoardResizing();

	//game process tests
	void testMarkUnMark();
	void testCheckVictory();
	void testMakeWinnerTurn();
	void testGameOverTurn();
	void testCellsChecking();

	void cleanup();
};

