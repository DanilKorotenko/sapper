#ifndef SBOARD_H
#define SBOARD_H

#include <QObject>
#include <QVector>

class SCell;

typedef QVector<SCell *> SCellVector;

class SBoard : public QObject
{
	Q_OBJECT
public:
	explicit SBoard(qint8 width, qint8 height, QObject *parent = 0);

	QVector<SCellVector> cells();

private:
	QVector<SCellVector> _cells;

};

#endif // SBOARD_H
