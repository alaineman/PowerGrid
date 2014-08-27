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
#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QThread>
#include <QLinkedList>
#include <QWaitCondition>
#include <QSet>

namespace entity {

class Task;
class TaskContext;
class TaskNotifier;
class TaskFactory;

/**
 * @brief Manager class for Task instances
 *
 * This class is responsible for running and queueing tasks. It is capable of
 * queueing multiple Tasks, after which they will be executed in the order they
 * were enqueued.
 *
 * The class runs on its own Thread, executing Tasks on its own once Tasks are
 * available. The status of the TaskManager can be monitored by connecting to its
 * signals, or by querying
 */
class TaskManager : public QThread {
    Q_OBJECT
    Q_DISABLE_COPY(TaskManager)
private:
    QSet<TaskFactory*> _factories;
    QLinkedList<Task*> _taskQueue;
    TaskContext* _context;
    TaskNotifier* _notifier;
    QWaitCondition _waitCondition;

    TaskFactory* _activeFactory;
public:
    explicit TaskManager(TaskNotifier* notifier, QObject* parent = NULL);
    ~TaskManager();

    /**
     * @brief Returns the amount of Tasks awaiting execution.
     * @return the amount of Tasks awaiting execution
     */
    int  amountWaiting()  const { return _taskQueue.size(); }
    /**
     * @brief Returns true is the amount of Tasks awaiting execution is 0.
     *
     * If this returns true, the TaskManager may or may not be still executing the last Task from the queue.
     * If it is desirable to know if the TaskManager is idle or not, please connect to the becameIdle() signal
     * instead.
     *
     * @return true if there are no more Tasks waiting, false otherwise.
     */
    bool isEmpty() const { return _taskQueue.isEmpty(); }

    QSet<TaskFactory*> factories() { return _factories; }
    TaskFactory* find(QString name);

    Task* instantiate(TaskFactory* factory);

protected:
    virtual void run();

private:
    void executeNextTask(QMutex* mutex);

signals:
    void taskStarted(Task* task);
    void taskFinished(Task* task);
    void taskFailed(Task* task, QString reason);

    void becameIdle();
    void becameActive();

public slots:
    void enqueue(Task* task);
    void enqueue(TaskFactory* factory);

    void addFactory(TaskFactory* factory);
    void removeFactory(TaskFactory* factory);
};

}

#endif // TASKMANAGER_H
