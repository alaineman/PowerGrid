#include "matcher.h"
#include "world.h"

namespace entity {

Matcher::Matcher(World *world) : QObject(world) {
    if (world == NULL) {
        throw std::runtime_error("NULL world is not allowed");
    }

    // Connect to the specified World.
    connect(world, SIGNAL(processingStarted), this, SLOT(beforeProcessing));
    connect(world, SIGNAL(processingFinished), this, SLOT(afterProcessing));
}

QList<QString> Matcher::matchedTypes() const {
    QList<QString> result;
    result << "*"; // Default matches all Components
    return result;
}

void Matcher::afterProcessing() {}
void Matcher::beforeProcessing() {}

void Matcher::process(Entity *e, Component *c) {
    Q_UNUSED(e)
    Q_UNUSED(c)
    // We throw an exception here because not overriding this makes the entire Matcher useless.
    QString errmsg = QStringLiteral("process(Entity*,Comp) not overwritten in Matcher class: ")
                     .append(staticMetaObject.className());
    throw std::runtime_error(errmsg.toStdString());
}

} // namespace entity
