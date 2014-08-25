#include "dummyclassifier.h"
#include "entity/entity.h"
#include "component/name.h"

namespace plugins {
namespace examples {

DummyClassifier::DummyClassifier() {}

void DummyClassifier::process(entity::Entity *e) {
    qDebug() << "DummyClassifier invoked with name:" << e->get<component::Name>();
}

}
}
