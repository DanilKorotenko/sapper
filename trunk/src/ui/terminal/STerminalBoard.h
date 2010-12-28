#ifndef STERMINALBOARD_H
#define STERMINALBOARD_H

#include "dataModel/DataModel.h"

class STerminalBoard : public SBoard
{
	Q_OBJECT
public:
	explicit STerminalBoard(QObject *parent = 0);
	STerminalBoard(quint8 width, quint8 height, QObject *parent = 0);


	QString stringRepresentation();

};

#endif // STERMINALBOARD_H
