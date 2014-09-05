/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef ENTITY_TASKNOTIFIER_H
#define ENTITY_TASKNOTIFIER_H

#include <QObject>
#include <QWaitCondition>

namespace entity {

class TaskNotifier : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(TaskNotifier)
private:
    QWaitCondition* _waiter;
public:
    TaskNotifier(QObject* parent = NULL);

    QWaitCondition* waiter() const { return _waiter; }

public slots:
    //TODO: connect this to World::processingFinished()
    void notifyWaiting();
};

} // namespace entity

#endif // ENTITY_TASKNOTIFIER_H
