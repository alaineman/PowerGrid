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
