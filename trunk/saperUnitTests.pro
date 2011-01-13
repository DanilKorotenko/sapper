######################################################################
# Copyright (C) 2011 Danil Korotenko (danil.korotenko@gmail.com)
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public Licence
# as published by the Free Software Foundation; either version 3
# of the Licence, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public Licence for more details.
#
# You should have received a copy of the GNU General Public Licence
# along with this program; if not, write to the Free Software Foundation,
# Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
######################################################################

TEMPLATE = app
CONFIG += qtestlib
INCLUDEPATH += ./src

# Input
HEADERS += 	src/UnitTests/dataModelTest.h \
	src/UnitTests/ConsoleUITest.h \
	src/saper.h \
	src/cell.h \
	src/saperbutton.h \
	src/saperboard.h \
	src/dataModel/scell.h \
	src/dataModel/sboard.h \
	src/ConsoleSapper/SConsoleBoard.h \
	src/ConsoleSapper/SConsoleCell.h

SOURCES += src/UnitTests/dataModelTest.cpp \
	src/UnitTests/ConsoleUITest.cpp \
	src/saper.cpp \
	src/cell.cpp \
	src/saperbutton.cpp \
	src/saperboard.cpp \
	src/dataModel/scell.cpp \
	src/dataModel/sboard.cpp \
	src/ConsoleSapper/SConsoleBoard.cpp \
	src/UnitTests/main.cpp \
	src/ConsoleSapper/SConsoleCell.cpp
