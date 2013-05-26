# GUConv
# Copyright (C) 2013 Simon Wilper
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

compiler = gcc
binaries = bin
target = $(binaries)/guconv

incdirs =\
	-Iinc\
	-I/usr/include/gtk-2.0\
	-I/usr/lib/gtk-2.0/include\
	-I/usr/include/atk-1.0\
	-I/usr/include/cairo\
	-I/usr/include/libdrm\
	-I/usr/include/gdk-pixbuf-2.0\
	-I/usr/include/glib-2.0\
	-I/usr/lib/glib-2.0/include\
	-I/usr/include/pango-1.0\
	-I/usr/include/libxml2

#	-I/usr/include/pango-1.0\
#	-I/usr/include/pixman-1\
#	-I/usr/include/pango-1.0\
#	-I/usr/include/freetype2\
#	-I/usr/include/libpng15\
#	-I/usr/include/harfbuzz\

src = src
rm = rm
inc = inc

libs =\
	-lgtk-x11-2.0\
	-lgobject-2.0\
	-lglib-2.0\
	-lxml2

#	-lgdk-x11-2.0\
#	-lpangocairo-1.0\
#	-latk-1.0\
#	-lcairo\
#	-lgdk_pixbuf-2.0\
#	-lgio-2.0\
#	-lpangoft2-1.0\
#	-lpango-1.0\
#	-lfreetype\
#	-lfontconfig\

flags = -pipe -Wall -g -pthread

.c.o:
	@echo "[CC ] $<"
	@$(compiler) -c $(incdirs) $(flags) -o "$@" "$<"

objects =\
	$(src)/main.o\
	$(src)/arithmetic.o\
	$(src)/xmlparser.o\
	$(src)/mainwindow.o

all: $(target)

$(src)/mainwindow.o : $(inc)/mainwindow.h
$(src)/arithmetic.o : $(inc)/arithmetic.h
$(src)/xmlparser.o : $(inc)/xmlparser.h

$(target) : $(objects)
	@echo "[LNK] $(target)"
	@$(compiler) -o $(target) $(objects) $(libs)

.PHONY : clean strip install

install :
	install $(target) $(HOME)/bin/guconv

clean :
	-@$(rm) $(binaries)/* $(src)/*.o 2>/dev/null

strip :
	strip -s $(target)

