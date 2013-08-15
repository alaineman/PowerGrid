/*
 * Copyright 2012-2013 Patrick Kramer, Vincent Wassenaar
 *
 * This file is part of PowerGrid.
 *
 * PowerGrid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PowerGrid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PowerGrid.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "basecomponent.h"


namespace cache {

Widget* BaseComponent::getWidget(int n1, int n2, int n3, int n4){
    if(n1<0){
        return 0;
    }
    Widget* w1 = findChild<Widget*>(QStringLiteral("widget_").append(QString::number(n1)), Qt::FindDirectChildrenOnly);
    if(n2<0 || w1==NULL){
        return w1;
    }
    Widget* w2 = w1->findChild<Widget*>(QStringLiteral("widget_").append(QString::number(n2)), Qt::FindDirectChildrenOnly);
    if(n3<0 || w2==NULL){
        return w2;
    }
    Widget* w3 = w2->findChild<Widget*>(QStringLiteral("widget_").append(QString::number(n3)), Qt::FindDirectChildrenOnly);
    if(n4<0 || w3==NULL){
        return w3;
    }
    return w3->findChild<Widget*>(QStringLiteral("widget_").append(QString::number(n4)), Qt::FindDirectChildrenOnly);
}

bool BaseComponent::containsWidget(int n1, int n2, int n3, int n4){
    return getWidget(n1,n2,n3,n4)!=NULL;
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
