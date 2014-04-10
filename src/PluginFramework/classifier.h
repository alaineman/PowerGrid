#ifndef PLUGINS_CLASSIFIER_H
#define PLUGINS_CLASSIFIER_H

#include <QObject>

namespace entity {
 class Entity;
}

namespace plugins {

/**
 * @brief Interface for classifying Entity types.
 *
 * Classifiers recognize and assign Components to Entities
 * to allow other classes to process these Entities
 * according to their properties.
 */
class Classifier : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(Classifier)
public slots:
    /**
     * \brief Processes the provided Entity.
     *
     * This assigns Components to this Entity based on
     * the Entity's already existing properties.
     *
     * \param e the Entity to process
     */
    virtual void process(entity::Entity* e) = 0;
};

} // namespace plugins

#endif // PLUGINS_CLASSIFIER_H
