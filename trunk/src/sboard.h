#ifndef SBOARD_H
#define SBOARD_H

#include <QObject>
#include <QSize>

class SBoard : public QObject
{
	Q_OBJECT
public:
	explicit SBoard(qint8 width, qint8 height, QObject *parent = 0);



};

#endif // SBOARD_H
