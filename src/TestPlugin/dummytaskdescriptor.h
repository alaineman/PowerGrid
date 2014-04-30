#ifndef DUMMYTASKDESCRIPTOR_H
#define DUMMYTASKDESCRIPTOR_H

#include "testplugin_global.h"
#include "taskdescriptor.h"

namespace plugins {
namespace examples {

class TESTPLUGINSHARED_EXPORT DummyTaskDescriptor : public TaskDescriptor {
public:
    DummyTaskDescriptor();

    void execute();
    quint64 cost() const throw() { return 200; }

};

}
}

#endif // DUMMYTASKDESCRIPTOR_H
