/**************************************************************************
** Copyright 2014 Patrick Kramer, Vincent Wassenaar
** This file is part of PowerGrid.
**
** PowerGrid is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** PowerGrid is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************************/

#include "fieldinfo.h"
#include "classinfo.h"

namespace jace {
namespace model {

FieldInfo::FieldInfo(QString name, ClassInfo *info)
    : Mappable(name, info), cls(info) {
    Q_ASSERT(info != NULL); // Must provide valid ClassInfo
}

FieldInfo::~FieldInfo() {
}

} // namespace model
} // namespace jace

