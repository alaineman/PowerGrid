#include "powergridplugin.h"

#include <iostream>

namespace plugins {
  using namespace std;

  void DummyTask::run() {
    cout << "Dummy Task is executed.";
  }

  QList<TaskDescriptor*> PowerGridPlugin::availableTasks() {
    QList<TaskDescriptor*> tasks ();
    tasks.append(new DummyTask());
    return tasks;
  }
}
