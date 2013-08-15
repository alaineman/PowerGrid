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
#ifndef BASECOMPONENT_H
#define BASECOMPONENT_H

#include <QMap>
#include "Local/widget.h"

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
