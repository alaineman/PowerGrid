#include "dummytaskdescriptor.h"
#include <QDebug>

namespace plugins {
namespace examples {

DummyTaskDescriptor::DummyTaskDescriptor()
    : TaskDescriptor(QStringLiteral("Dummy Task"),
                     QStringLiteral("A dummy Task that does nothing.")){
}

void DummyTaskDescriptor::execute() {
    qDebug() << "DummyTask executed";
}

}
}
