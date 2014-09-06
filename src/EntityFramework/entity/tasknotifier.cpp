#include "tasknotifier.h"

namespace entity {

TaskNotifier::TaskNotifier(QObject* parent) :
    QObject(parent), _waiter(new QWaitCondition) {
}

void TaskNotifier::notifyWaiting() {
    _waiter->wakeAll();
}

} // namespace entity
