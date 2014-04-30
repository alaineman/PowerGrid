#ifndef DUMMYCLASSIFIER_H
#define DUMMYCLASSIFIER_H

#include "testplugin_global.h"
#include "entity/classifier.h"

namespace plugins {
namespace examples {

using entity::Classifier;
using entity::Entity;

class TESTPLUGINSHARED_EXPORT DummyClassifier : Classifier {
public:
    DummyClassifier();
    void process(Entity* e);
};

}
}

#endif // DUMMYCLASSIFIER_H
