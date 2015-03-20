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

#ifndef JACE_MODEL_FIELDINFO_H
#define JACE_MODEL_FIELDINFO_H

#include <QObject>
#include "mappable.h"

namespace jace {
namespace model {

class ClassInfo;

/**
 * @brief Mapped non-static field in the JVM.
 *
 * This class represents a non-static field with an optional mapping.
 */
class FieldInfo : public Mappable {
    Q_OBJECT
    Q_DISABLE_COPY(FieldInfo)

    ClassInfo* cls;
public:
    /**
     * @brief Constructs a new field with the given name.
     * @param name - The real name of the field
     * @param info - The Class this field belongs to
     */
    FieldInfo(QString name, ClassInfo *info);
    virtual ~FieldInfo();

    /**
     * @brief The owning class of this field
     * @return The owning class of this field
     */
    ClassInfo* owner() const { return cls; }
};

} // namespace model
} // namespace jace

#endif // JACE_MODEL_FIELDINFO_H
