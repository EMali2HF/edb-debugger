/*
Copyright (C) 2006 - 2015 Evan Teran
                          evan.teran@gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CHECKVERSION_20061122_H_
#define CHECKVERSION_20061122_H_

#include "IPlugin.h"
#include "Types.h"

class QMenu;
class State;

namespace DumpStatePlugin {

class DumpState : public QObject, public IPlugin {
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "edb.IPlugin/1.0")
	Q_CLASSINFO("author", "Evan Teran")
	Q_CLASSINFO("url", "http://www.codef00.com")

public:
	DumpState();
	virtual ~DumpState();

public:
	virtual QMenu *menu(QWidget *parent = nullptr);

public Q_SLOTS:
	void show_menu();

private:
	virtual QWidget *options_page();

private:
	void dump_code(const State &state);
	void dump_registers(const State &state);
	void dump_stack(const State &state);
	void dump_data(edb::address_t address);
	void dump_lines(edb::address_t address, int lines);

private:
	QMenu * menu_;
};

}

#endif
