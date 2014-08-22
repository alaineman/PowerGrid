#include "taskmanager.h"
#include "task.h"
#include "taskcontext.h"
#include "tasknotifier.h"

namespace entity {

TaskManager::TaskManager(TaskNotifier *notifier, QObject* parent) :
        QThread(parent), _context(new TaskContext), _notifier(notifier) {
    if (!_notifier) {
        throw std::invalid_argument("Invalid TaskNotifier");
    }
    setObjectName(QStringLiteral("PG_TaskManager"));
    _context->supplyWaitCondition(_notifier->waiter());
}

TaskManager::~TaskManager() {
    delete _context;
}

void TaskManager::run() {
    setTerminationEnabled(false);
    QMutex* mutex = new QMutex;
    while (!isInterruptionRequested()) {
        executeNextTask(mutex);
    }
    delete mutex;
}

void TaskManager::executeNextTask(QMutex* mutex) {
    if (!mutex) throw std::invalid_argument("NULL");
    mutex->lock();
    if (_taskQueue.isEmpty()) {
        emit becameIdle();
        _waitCondition.wait(mutex);
        emit becameActive();
    }
    Task* next = _taskQueue.takeFirst();
    mutex->unlock();
    try {
        emit taskStarted(next);
        next->execute(_context);
        emit taskFinished(next);
    } catch (std::exception& ex) {
        emit taskFailed(next, ex.what());
    } catch (QString& message) {
        emit taskFailed(next, message);
    } catch (...) {
        emit taskFailed(next, "Unknown error");
    }
}

void TaskManager::enqueue(Task *task) {
    if (!task) throw std::invalid_argument("NULL");
    _taskQueue.append(task);
    _waitCondition.wakeAll();
}

}
