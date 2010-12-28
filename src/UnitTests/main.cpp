#include <QTest>

#include "UnitTests/dataModelTest.h"
#include "UnitTests/ConsoleUITest.h"

int main(int argc, char ** argv)
{
	DataModelTest dataModelTests;
	QTest::qExec(&dataModelTests, argc, argv);

	ConsoleUITest consoleUITests;
	QTest::qExec(&consoleUITests, argc, argv);

	return 0;
}
