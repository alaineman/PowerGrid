#include "basecomponent.h"


namespace cache {

Widget* BaseComponent::getWidget(int n1, int n2, int n3, int n4){
    if(n1<0){
        return 0;
    }
    Widget* w1 = findChild<Widget*>(QStringLiteral("widget_").append(QString::number(n1)), Qt::FindDirectChildrenOnly);
    if(n2<0 || w1->isNull()){
        return w1;
    }
    Widget* w2 = w1->findChild<Widget*>(QStringLiteral("widget_").append(QString::number(n2)), Qt::FindDirectChildrenOnly);
    if(n3<0 || w2->isNull()){
        return w2;
    }
    Widget* w3 = w2->findChild<Widget*>(QStringLiteral("widget_").append(QString::number(n3)), Qt::FindDirectChildrenOnly);
    if(n4<0 || w3->isNull()){
        return w3;
    }
    return w3->findChild<Widget*>(QStringLiteral("widget_").append(QString::number(n4)), Qt::FindDirectChildrenOnly);
}

bool BaseComponent::containsWidget(int n1, int n2, int n3, int n4){
    return !getWidget(n1,n2,n3,n4)->isNull();
}

void BaseComponent::clearWidget(Widget* widget){
    widget->setParent(NULL);
    widget->deleteLater();
}

void BaseComponent::clearAll(){
    QObjectList qol = children();
    for (QObjectList::iterator it = qol.begin(); it != qol.end(); ++it) {
        clearWidget((Widget*)(*it));
    }
}

}
