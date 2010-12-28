#include <QTest>

#include "UnitTests/dataModelTest.h"
#include "UnitTests/TerminalUITest.h"

int main(int argc, char ** argv)
{
	DataModelTest dataModelTests;
	QTest::qExec(&dataModelTests, argc, argv);

	TerminalUITest terminalUITests;
	QTest::qExec(&terminalUITests, argc, argv);

	return 0;
}
