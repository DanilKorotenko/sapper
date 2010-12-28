#ifndef STERMINALBOARD_H
#define STERMINALBOARD_H

#include <QObject>
#include <QPointer>

class SBoard;

class STerminalBoard : public QObject
{
	Q_OBJECT
public:
	STerminalBoard(QObject *parent = 0);

	void setBoardSize(quint8 sizeX, quint8 sizeY);
	void resetBoard();

	QString boardStringRepresentation();

public slots:

private:
	QPointer<SBoard> _board;
};

#endif // STERMINALBOARD_H
