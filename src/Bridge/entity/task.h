#ifndef TASK_H
#define TASK_H

#include <QObject>

namespace entity {

class TaskContext;

/**
 * @brief Represents a single Task in the bot
 *
 * A Task is the smallest unit of work to be done to realize some goal.
 * Tasks can refer to, and call other Tasks to delegate part of the work
 * to be done.
 *
 * Tasks can pass instructions to the TaskContext available when the Task
 * is running.
 */
class Task : public QObject {
    Q_OBJECT
private:
    QString      _name;
    TaskContext* _context;
    Task*        _parent;
public:
    /**
     * @brief Creates a new Task with the given name and parent.
     * @param name   - the name of the Task
     * @param parent - the parent Task for this Task, default is NULL.
     */
    Task(QString name, Task* parent = NULL);

    /**
     * @brief Returns the TaskContext instance for this Task.
     *
     * This function may return NULL when this Task is not running,
     * but while this Task is running, the return value is guaranteed
     * to point to a valid TaskContext.
     *
     * @return the TaskContext for this Task
     */
    TaskContext* context() const { return _context; }

    /**
     * @brief  Returns the name of this Task
     * @return the name of this Task
     */
    QString name() const { return _name; }

    /**
     * @brief  Returns the parent of this Task
     * @return the parent of this Task, or NULL if this Task has no parent.
     */
    Task* parentTask() const { return _parent; }

    /**
     * @brief Runs this Task once.
     *
     * This pure-virtual member function should be implemented in Task subclasses.
     * To run this Task properly, please
     *
     * The return value indicates whether the Task should loop or not. A return
     * value of true indicates the Task is finished, while a return value of
     * false indicates the Task should be run again.
     *
     * @return True if the Task is done, false if the Task should be repeated.
     */
    virtual bool run() = 0;

    /**
     * @brief Executes this Task properly
     *
     * The provided TaskContext is used to run the Task.
     *
     * This function may throw anything as a result of executing the
     * run() member function. Implementations should state possible
     * thrown exceptions in their documentation.
     *
     * @param context - the TaskContext to use while running the Task
     */
    void execute(TaskContext* context);
};

}

#endif // TASK_H
