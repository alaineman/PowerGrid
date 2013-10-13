#include "powergridplugin.h"

#include <iostream>

namespace plugins {
  void DummyTask::run() {
    cout << "Dummy Task is executed.";
  }

  QList<TaskDescriptor> PowerGridPlugin::availableTasks() {
    QList<TaskDescriptor> tasks ();
    tasks.append(DummyTask());
    return tasks;
  }
}
