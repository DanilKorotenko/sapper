#ifndef SCONSOLEBOARD_H
#define SCONSOLEBOARD_H

#include "dataModel/sboard.h"

class SConsoleCell;

class SConsoleBoard : public SBoard
{
	Q_OBJECT
public:
	explicit SConsoleBoard(QObject *parent = 0);
	SConsoleBoard(quint8 width, quint8 height, QObject *parent = 0);

	QString stringRepresentation();

protected:
	SCell *createCell();

};

#endif // SCONSOLEBOARD_H
