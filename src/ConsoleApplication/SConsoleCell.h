#ifndef SCONSOLECELL_H
#define SCONSOLECELL_H

#include "dataModel/scell.h"

class SConsoleCell : public SCell
{
	Q_OBJECT
public:
	explicit SConsoleCell(QObject *parent = 0);

	QString stringRepresentation(bool gameOver);

};

#endif // SCONSOLECELL_H
