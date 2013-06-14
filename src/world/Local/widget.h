#ifndef WIDGET_H
#define WIDGET_H

#include "jniobject.h"
#include "widgetcomponent.h"

namespace world {

  class Widget : public jni::JNIObject {
    private:
      Q_DISABLE_COPY(Widget)
      vector<WidgetComponent*> components;
    public:
      Widget(jobject obj) : JNIObject(obj){}
      vector<WidgetComponent*> getComponents(bool useCache = true);

  };

}
#endif // WIDGET_H
