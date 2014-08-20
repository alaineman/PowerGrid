#include "testplugin.h"
#include "dummytaskdescriptor.h"
#include "dummyclassifier.h"

namespace plugins {
namespace examples {

using entity::Classifier;

TestPlugin::TestPlugin() {}
TestPlugin::~TestPlugin() {}

QList<TaskDescriptor*> TestPlugin::tasks() const {
    return QList<TaskDescriptor*>( {
        new DummyTaskDescriptor()
    } );
}

QList<Classifier*> TestPlugin::classifiers() const {
    return QList<Classifier*>( {
        new DummyClassifier()
    } );
}

}
}
