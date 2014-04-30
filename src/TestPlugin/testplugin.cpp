#include "testplugin.h"
#include "dummytaskdescriptor.h"

namespace plugins {
namespace examples {

TestPlugin::TestPlugin() {}
TestPlugin::~TestPlugin() {}

QList<TaskDescriptor*> TestPlugin::tasks() const {
    return QList<TaskDescriptor*>( {
        new DummyTaskDescriptor()
    } );
}

QList<Classifier*> TestPlugin::classifiers() const {
    return QList<Classifier*>();
}

}
}
