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

	qint8 numberOfBombsArround();
	void setNumberOfBombsArround(qint8 value);

private:
	bool _hasBomb;
	bool _checked;
	qint8 _numberOfBombsArround;

};

#endif // SCELL_H
