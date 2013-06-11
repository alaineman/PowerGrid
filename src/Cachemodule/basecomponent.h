#ifndef BASECOMPONENT_H
#define BASECOMPONENT_H

#include <QMap>
#include "widget.h"

using namespace world;

namespace cache{

    class BaseComponent : public QObject{
      public:
        explicit BaseComponent(QObject* parent = NULL):QObject(parent){}
        Widget* getWidget(int n1, int n2 = -1, int n3 = -1, int n4 = -1);
        bool containsWidget(int n1, int n2 = -1, int n3 = -1, int n4 = -1);
    public slots:
        void clearWidget(Widget* widget);
        void clearAll();
    };
}
#endif
