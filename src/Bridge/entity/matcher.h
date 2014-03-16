#ifndef ENTITY_MATCHER_H
#define ENTITY_MATCHER_H

#include <QObject>

namespace entity {

class Entity;
class Component;
class World;

/**
 * \brief Processing class for Entity objects
 *
 * This class can be used to create Matcher classes that operate on Entities
 * with a certain type of Component.
 *
 * Characteristic behavior for Matcher objects is, that they operate on a subset of
 * similar Entities. For operating on a single Entity only, please take a look
 * at the Operator class instead.
 */
class Matcher : public QObject {
    Q_OBJECT
public:
    /**
     * \brief Creates a new Matcher for the given world.
     * \param world the world this Matcher registers to.
     * \throws std::runtime_error if \c world == NULL
     */
    Matcher(World* world);

    /**
     * \brief Returns a QList of names of Component types this Matcher matches.
     *
     * The default implementation returns a QList with a single element "*", indicating
     * all Components are matched by this Matcher. Returning an empty QList indicates
     * no Component types are matched.
     *
     * This should be overridden to return the correct Component types for this Matcher.
     *
     * \return a QList indicating the types matched by this Matcher
     */
    virtual QList<QString> matchedTypes() const;
signals:
    /**
     * \brief signal emitted to indicate processing should be aborted.
     *
     * After this signal is sent and processed by the World, the process
     * slot will no longer be invoked for this Matcher for the remainder of the cycle. If
     * the signal is emitted during invocation of the \c beforeProcessing() slot, Entity
     * processing for this Matcher is disabled for the duration of the entire cycle. On
     * the contrary, if this signal is emitted from \c afterProcessing(), it has no
     * effect at all.
     */
    void abortProcessing();
public slots:
    /**
     * \brief Processes a single Entity-Component combination.
     *
     * This slot is repeatedly invoked in a cycle with all Entities that are
     * matched by this Matcher.
     *
     * This slot should be overridden to perform the actual processing.
     * The default implementation throws a std::runtime_error.
     *
     * Any exceptions thrown by this slot are ignored.
     * \internal Perhaps we should show these in some log window later...
     *
     * \param e the Entity the Component belongs to
     * \param c the Component matched by this Matcher
     */
    virtual void process(Entity* e, Component* c);
    /**
     * \brief Executed at the beginning of a cycle before Entities are processed.
     *
     * This slot is invoked before any Entities are processed. Matchers can perform
     * any required setup here. The default implementation does nothing.
     *
     * If this slot throws any kind of exception, processing will be skipped for this
     * Matcher. This can be used to process Entities only under some circumstances.
     */
    virtual void beforeProcessing();
    /**
     * \brief Executed after all Entities have been processed in this cycle.
     *
     * This slot is invoked after all Entities are processed. Matchers can perform
     * any required cleanup when this slot is invoked. The default implementation
     * does nothing.
     */
    virtual void afterProcessing();
};

} // namespace entity

#endif // ENTITY_MATCHER_H
