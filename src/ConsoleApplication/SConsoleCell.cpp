#include "SConsoleCell.h"

SConsoleCell::SConsoleCell(QObject *parent) : SCell(parent)
{
}

QString SConsoleCell::stringRepresentation(bool gameOver)
{
	QString result;
	if (hasBomb() && gameOver && !flagged())
	{
		result ="*";
	}
	else if (hasBomb() && gameOver && flagged())
	{
		result = "-";
	}
	else if (flagged())
	{
		result = "F";
	}
	else if (0 == numberOfBombs())
	{
		result = " ";
	}
	else
	{
		result.append(QString("%1").arg(numberOfBombs()));
	}
	return result;
}
