#include "world.h"
#include "entity.h"
#include "component.h"

#include <QMap>
#ifdef Q_COMPILER_INITIALIZER_LISTS
using std::initializer_list;
#endif

namespace entity {

World* World::theWorld = new World();

World::~World() Q_DECL_NOTHROW {
    foreach(Entity* e, entities) {
        e->deleteLater();
    }
}

Entity* World::createEntity() {
    Entity* e = new Entity();
    entities << e;
    emit entityCreated(e);
    return e;
}

int World::count() {
    return entities.count();
}

void World::addMatcher(Matcher *m) {
    if (m) {
        foreach(QString s, m->matchedTypes()) {
            QMap<QString, QList<Matcher*>>::Iterator it = matchers.find(s);
            if (it == matchers.end()) {
                matchers.insert(s, QList<Matcher*>() << m);
            } else {
                (*it) << m;
            }
        }
    }
}

void World::removeMatcher(Matcher *m) {
    if (m) {
        foreach(QString s, m->matchedTypes()) {
            QMap<QString, QList<Matcher*>>::Iterator it = matchers.find(s);
            if (it != matchers.end()) {
                (*it).removeOne(m);
            }
        }
    }
}

#ifdef Q_COMPILER_INITIALIZER_LISTS

Entity* World::createEntity(initializer_list<Component*> comps) {
    Entity* e = createEntity();
    initializer_list<Component*>::iterator it = comps.begin();
    for (; it != comps.end(); it++) {
        e->addComponent(*it);
    }
    return e;
}

#endif

void World::deleteEntity(Entity *e) {
    entities.removeOne(e);
    foreach (Component* c, e->components) {
        QList<Entity*> cList = componentMap.value(c->metaObject()->className(), QList<Entity*>());
        cList.removeOne(e);
        if (cList.isEmpty()) {
            componentMap.remove(c->metaObject()->className());
        }
        e->removeComponent(c);
        c->deleteLater();
    }
    e->deleteLater();
}

void World::processAll() {
    emit processingStarted();

    QMapIterator<QString, QList<Matcher*>> it (matchers);
    for (;it.hasNext(); it.next()) {                        // For each Component type
        QList<Entity*> ents = componentMap.value(it.key()); // The Entities with this Component
        foreach(Matcher* m, it.value()) {                   // Now for each Matcher,
            foreach(Entity* e, ents) {                      // and for each Entity:
                m->process(e, e->get(it.key()));            // process the Entity
            }
        }
    }

    emit processingFinished();
}

}
