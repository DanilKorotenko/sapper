#include "sboard.h"

#include "scell.h"

SBoard::SBoard(qint8 width, qint8 height, QObject *parent) : QObject(parent)
{
	if ((0 == width) || (0 == height))
	{
		delete this;
	}

	for (qint8 indexX = 0; indexX < width; indexX++)
	{
		SCellVector cellsVector;
		for (qint8 indexY = 0; indexY < height; indexY++)
		{
			cellsVector.push_back(new SCell(this));
		}
		_cells.push_back(cellsVector);
	}
}

QVector<SCellVector> SBoard::cells() const
{
	return _cells;
}
