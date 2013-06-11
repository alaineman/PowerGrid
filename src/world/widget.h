#ifndef WIDGET_H
#define WIDGET_H

#include <QtCore>

namespace world {

  typedef unsigned short widget_id;

  class Widget : public QObject {
    Q_OBJECT
    private:
      Q_DISABLE_COPY(Widget)

      widget_id id;
    public:
      Widget(widget_id w_id, Widget* parent = NULL) : QObject(parent) { id = w_id; }
      widget_id GetID() { return id; }
      bool isNull() { return id==0; }
  };

}
#endif // WIDGET_H
