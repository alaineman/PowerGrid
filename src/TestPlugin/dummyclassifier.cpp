#include "dummyclassifier.h"
#include "entity/entity.h"
#include "api/component/name.h"

namespace plugins {
namespace examples {

DummyClassifier::DummyClassifier() {}

void DummyClassifier::process(entity::Entity *e) {
    qDebug() << "DummyClassifier invoked with name:" << e->get<api::component::Name>();
}

}
}
