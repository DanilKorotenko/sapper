#include "STerminalApplication.h"

static char const * kApplicationName = "Sapper";

STerminalApplication::STerminalApplication(int & argc, char ** argv) :
	QCoreApplication(argc, argv)
{
	this->setApplicationName(kApplicationName);
}
