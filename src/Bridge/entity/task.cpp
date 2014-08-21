#include "task.h"

namespace entity {

Task::Task(QString name, Task *parent) :
    QObject(parent), _name(name), _parent(parent) {

}

void Task::execute(TaskContext *context) {
    if (!context) {
        throw std::invalid_argument("TaskContext is invalid");
    }
    _context = context;
    bool done;
    do {
        done = run();
    } while (!done);
}

}
