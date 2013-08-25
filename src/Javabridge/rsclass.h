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

#ifndef CLASSENUMS_H
#define CLASSENUMS_H

/// Enum defining unique IDs for all RS classes.
enum RSClass {
  NONE, // special case of no class or undefined class.

  // please leave all below entries in alphabetical order for easy lookup

  ANIMABLEENTITY,
  ANIMABLEENTITYNODE,
  ANIMATEDBOUNDARY,
  ANIMATEDEVENTOBJECT,
  ANIMATEDFLOORDECORATION,
  ANIMATEDWALLDECORATION,
  ANIMATION,
  ANIMATOR,

  BOUNDARY,

  CACHABLENODE,
  CACHE,
  CHARACTER,
  CHARACTERANIMATOR,
  CHATMESSAGE,
  CLIENT,
  COLLISIONDATA,
  COMBATBAR,
  COMBATBARDATA,

  DEQUE,
  DEQUENODE,
  DIRECTXMODEL,
  DIRECTXTOOLKIT,

  ENGINE,
  ENTITY,
  ENTITYDATA,
  EVENTOBJECT,

  FLOORDECORATION,

  GRANDEXCHANGEOFFER,
  GRAPHIC,
  GRAPHICCACHELOADER,
  GRAPHICSTOOLKIT,

  HARDREFERENCE,
  HASHTABLE,
  HINTARROW,

  ITEMCACHELOADER,
  ITEMDEFINITION,
  ITEMNODE,
  ITEMPILE,

  JAVAMODEL,
  JAVATOOLKIT,

  LINKEDLIST,
  LINKEDLISTNODE,

  MATRIX4F,
  MODEL,

  NODE,
  NPC,
  NPCCACHELOADER,
  NPCCOMPOSITE,

  OBJECTCACHELOADER,
  OBJECTCOMPOSITE,
  OBJECTDEFINITION,
  OBJECTNODE,
  OPENGLMODEL,
  OPENGLTOOLKIT,

  PLAYER,
  PLAYERCOMPOSITE,
  PLAYERFACADE,
  PROJECTILE,
  PROJECTILENODE,

  QUEUE,

  REGION,
  REGIONBASE,
  REGIONGRID,
  RENDERABLEENTITY,

  SKILL,
  SKILLCOMPOSITE,
  SOFTREFERENCE,

  TILE,
  TILEHEIGHTS,

  VARPS,
  VECTOR3D,

  WALLDECORATION,
  WIDGET,
  WIDGETCOMPONENT
};

#endif // CLASSENUMS_H
