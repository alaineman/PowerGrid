#include "taskcontext.h"

#include <QThread>

namespace entity {

TaskContext::TaskContext(QObject *parent) :
    QObject(parent) {
}

void TaskContext::waitUntil(ConditionFunc condition) {
    emit waitStarted();
    forever {
        _mutex.lock();
        _waiter->wait(&_mutex);
        if (condition()) {
            _mutex.unlock();
            emit waitStopped();
            return;
        }
        _mutex.unlock();
    }
}

void TaskContext::wait(ulong msecs) {
    emit waitStarted();
    QThread::currentThread()->msleep(msecs);
    emit waitStopped();
}

void TaskContext::supplyWaitCondition(QWaitCondition *waiter) {
    if (_waiter) {
        throw std::logic_error("QWaitCondition already set");
    }
    if (waiter) {
        _waiter = waiter;
    } else {
        throw std::invalid_argument("Invalid QWaitCondition: NULL");
    }
}

} // namespace entity
