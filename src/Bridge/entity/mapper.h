#ifndef ENTITY_MAPPER_H
#define ENTITY_MAPPER_H

#include <QObject>
#include <QMap>

namespace entity {

class World;
class Component;
class Entity;

class Mapper : public QObject{
    Q_OBJECT
    Q_DISABLE_COPY(Mapper)
private:
    QString type;
    QMap<Component*,Entity*> map;
public:
    Mapper(QString type, World* parent = 0);
    bool contains(Entity* e) const;
    Entity* getEntity(Component *key) const;
    QString getMappedType() const;
public slots:
    void remove(Entity* e, Component* cmp);
    void add(Entity* e, Component* cmp);
};

} // namespace entity

#endif // ENTITY_MAPPER_H
