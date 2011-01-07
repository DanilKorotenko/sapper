#include "SConsoleCell.h"

SConsoleCell::SConsoleCell(QObject *parent) : SCell(parent)
{
}

QString SConsoleCell::stringRepresentation(bool gameOver)
{
	QString result;

	if (checked())
	{
		if (0 == numberOfBombs())
		{
			result = " ";
		}
		else
		{
			result.append(QString("%1").arg(numberOfBombs()));
		}
	}
	else if (gameOver)
	{
		if (flagged())
		{
			if (hasBomb())
			{
				result = "F";
			}
			else
			{
				result = "-";
			}
		}
		else if (hasBomb())
		{
			result = "*";
		}
		else
		{
			result = " ";
		}
	}
	else if (flagged())
	{
		result = "F";
	}
	else
	{
		result = "?";
	}

	return result;
}
