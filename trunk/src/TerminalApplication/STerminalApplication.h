#ifndef STERMINALAPPLICATION_H
#define STERMINALAPPLICATION_H

#include <QCoreApplication>

class STerminalApplication : public QCoreApplication
{
	Q_OBJECT
public:
	STerminalApplication(int & argc, char ** argv);

};

#endif // STERMINALAPPLICATION_H
