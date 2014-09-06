#include "task.h"
#include <QThread>

namespace entity {

Task::Task(QString name, Task *parent) :
    QObject(parent), _name(name) {

}

void Task::execute(TaskContext *context) {
    if (!context) {
        throw std::invalid_argument("TaskContext is invalid");
    }
    _context = context;
    bool done;
    emit executionStarted();
    do {
        done = run();
    } while (!done && !QThread::currentThread()->isInterruptionRequested());
    emit executionFinished();
}

}
