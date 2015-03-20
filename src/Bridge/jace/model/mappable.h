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

#ifndef JACE_MODEL_MAPPABLE_H
#define JACE_MODEL_MAPPABLE_H

#include <QObject>
#include <QString>

namespace jace {
namespace model {

/**
 * @brief Base class for Mappable objects.
 *
 * Mappable objects can be renamed dynamically to provide a
 * mapping layer over entities in the JVM.
 */
class Mappable : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(Mappable)

    QString real, mapped;
public:
    explicit Mappable(QString name, QObject *parent = 0);
    virtual ~Mappable();

    QString realName()   const { return real; }
    QString mappedName() const { return mapped; }
    QString activeName() const { return mapped.isEmpty() ? real : mapped; }
    bool    isMapped()   const { return !mapped.isEmpty(); }
signals:
    void nameChanged(QString oldName, QString mappedName);
public slots:
    void changeName(const QString newMappedName);
};

} // namespace model
} // namespace jace

#endif // JACE_MODEL_MAPPABLE_H
