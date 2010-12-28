#ifndef SBOARD_H
#define SBOARD_H

#include <QObject>
#include <QVector>

class SCell;

typedef QVector<SCell *> SCellVector;

enum SGameCondition
{
	kSContinue = 0,
	kSBombed,
	kSWinned
};

class SBoard : public QObject
{
	Q_OBJECT
public:
	explicit SBoard(quint8 width, quint8 height, QObject *parent = 0);

	SGameCondition makeTurn(quint8 indexX, quint8 indexY, bool setFlag);

	// Starts the checking of board from the specified cell.
	// Set to neighbours cells status checked and numbers of bombs around.
	// Iterative process. Calls this method for nested cells.
	void check(qint8 indexX, qint8 indexY);

	bool checkVictory();

	QVector<SCellVector> _cells;

private:



};

#endif // SBOARD_H
