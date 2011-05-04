#ifndef SCELL_H
#define SCELL_H

#include <QObject>

class SCell : public QObject
{
	Q_OBJECT
public:
	explicit SCell(QObject *parent = 0);

	bool hasBomb();
	void setHasBomb(bool value);

	bool checked();
	void setChecked(bool value);

	bool flagged();
	void toggleFlag();

	quint8 numberOfBombs();
	void setNumberOfBombsArround(quint8 value);

private:
	bool _hasBomb;
	bool _checked;
	bool _flagged;
	qint8 _numberOfBombs;

};

#endif // SCELL_H
