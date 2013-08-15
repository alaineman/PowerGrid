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
#include "sector.h"

namespace cache {

Sector::~Sector(){
    while (! collision_maps.empty()) {
        jbyte* elem = collision_maps.back();
        collision_maps.pop_back();
        delete elem;
    }
}

uint Sector::getIndexForPlane(int z){
    if (z < 0) {
        return -2 * z;
    } else if (z > 0) {
        return 2 * (z - 1);
    } else {
        return 0;
    }    
}

JNIObject* Sector::getObject(){
  return JNIObject::Null();
}

void Sector::setObject(){
}

jbyte Sector::getObjectCount(){
    return objects.size();
}

void Sector::removeCollisionMap(int z){
    int index = static_cast<int>(getIndexForPlane(z));
    while(collision_maps.size()>= index){
        jbyte* elem = collision_maps.back();
        delete elem;
        collision_maps.pop_back();
    }
}

jbyte Sector::getCollision(jbyte x,jbyte y, int z){
    ensurePlane(z);
    jbyte* map = collision_maps.at(z);
    return map[64*x + y];
}

void Sector::setCollision(jbyte x,jbyte y, int z, jbyte value){
    ensurePlane(z);
    jbyte* map = collision_maps.at(z);
    map[64*x + y] = value;
}

void Sector::ensurePlane(int z){
    int index = static_cast<int>(getIndexForPlane(z));
    while(collision_maps.size()<=index){
        collision_maps.push_back(new jbyte[64*64]);
    }
}

}
