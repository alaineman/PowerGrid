#ifndef ENTITY_MAPPER_H
#define ENTITY_MAPPER_H

#include <QObject>
#include <QMap>

namespace entity {

class World;
class Component;
class Entity;

template <typename Key> class Mapper : public QObject{
    Q_OBJECT
    Q_DISABLE_COPY(Mapper)
private:
    QMap<Key,Entity*> map;
public:
    Mapper(World* parent = 0);
    bool contains(Entity* e);
    Entity* getEntity(Key key);
public slots:
    void remove(Entity* e, Component* cmp);
    void add(Entity* e, Component* cmp);
};

} // namespace entity

#endif // ENTITY_MAPPER_H
