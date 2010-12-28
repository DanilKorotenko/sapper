#include "STerminalBoard.h"

#include "dataModel/DataModel.h"

STerminalBoard::STerminalBoard(QObject *parent) : QObject(parent)
{

}

void STerminalBoard::setBoardSize(quint8 sizeX, quint8 sizeY)
{
	_board = new SBoard(sizeX, sizeY);

}

void STerminalBoard::resetBoard()
{

}

QString STerminalBoard::stringRepresentation()
{
	return QString();
}
