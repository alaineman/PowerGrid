/*
 * Copyright 2014 Patrick Kramer, Vincent Wassenaar
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

#ifndef CLIENT_H
#define CLIENT_H

#include "MethodHelper.h"

#include "jace/RSClass.h"
#include "java/lang/object.h"

using namespace jace::proxy::types;
using namespace java::lang;

// Forward declarations of Java API classes
namespace java {
 namespace lang {
  class String;
 }
 namespace awt {
  class Rectangle;
 }
 namespace util {
  class Map;
 }
}

namespace api {
namespace bridge {

// Forward declarations of RS classes
class Camera;
class Canvas;
class NodeSubQueue;
class GrandExchangeOffer;
class DetailInfoNode;
class Facade;
class Friend;
class GraphicsToolkit;
class Interface;
class HashTable;
class ItemDefLoader;
class LandscapeInfo;
class HintArrow;
class NPCNode;
class OverheadMessage;
class Player;
class Deque;
class Mouse;
class Sprite;
class ObjectDefLoader;
class Cache;
class Server;

class Client : public Object {
public:
    // Macro defining required framework methods and constructors
    RS_OBJECT(Client)

    JACE_PROXY_API static Client getClient();

    JACE_PROXY_API Camera getCamera();
    JACE_PROXY_API Canvas getCanvas();
    JACE_PROXY_API java::util::Map getChatChannels();
    JACE_PROXY_API NodeSubQueue getCollapsedMenuItems();
    JACE_PROXY_API JInt getConnectionState();
    JACE_PROXY_API String getCurrentAction();
    JACE_PROXY_API QList<GrandExchangeOffer> getCurrentGrandExchangeOffers();
    JACE_PROXY_API JInt getDestinationX();
    JACE_PROXY_API JInt getDestinationY();
    JACE_PROXY_API DetailInfoNode getDetailInfoNode();
    JACE_PROXY_API JInt getFPS();
    JACE_PROXY_API Facade getFacade();
    JACE_PROXY_API JInt getFrameTime();
    JACE_PROXY_API QList<Friend> getFriendsList();
    JACE_PROXY_API GraphicsToolkit getGraphicsToolkit();
    JACE_PROXY_API QList<Interface> getInterfaceArray();
    JACE_PROXY_API QList<java::awt::Rectangle> getInterfaceBoundsArray();
    JACE_PROXY_API JInt getInterfaceIndex();
    JACE_PROXY_API HashTable getInterfaceNodeCache();
    JACE_PROXY_API ItemDefLoader getItemDefLoader();
    JACE_PROXY_API LandscapeInfo getLandscapeInfo();
    JACE_PROXY_API String getLastSelectedItemName();
    JACE_PROXY_API QList<HintArrow> getLoadedHintArrows();
    JACE_PROXY_API HashTable getLoadedItems();
    JACE_PROXY_API JInt getLoadedNPCCount();
    JACE_PROXY_API QList<NPCNode> getLoadedNPCNodes();
    JACE_PROXY_API QList<OverheadMessage> getLoadedOverheadMessages();
    JACE_PROXY_API QList<Player> getLoadedPlayers();
    JACE_PROXY_API Deque getLoadedProjectiles();
    JACE_PROXY_API Player getLocalPlayer();
    JACE_PROXY_API JInt getLoopCycle();
    JACE_PROXY_API JInt getMenuHeight();
    JACE_PROXY_API Deque getMenuItems();
    JACE_PROXY_API QList<String> getMenuOptions();
    JACE_PROXY_API JInt getMenuOptionsCount();
    JACE_PROXY_API JInt getMenuOptionsCountCollapsed();
    JACE_PROXY_API JInt getMenuWidth();
    JACE_PROXY_API JInt getMenuX();
    JACE_PROXY_API JInt getMenuY();
    JACE_PROXY_API JInt getMessageCounter();
    JACE_PROXY_API JFloat getMinimapAngle();
    JACE_PROXY_API JInt getMinimapOffset();
    JACE_PROXY_API JInt getMinimapScale();
    JACE_PROXY_API JInt getMinimapSetting();
    JACE_PROXY_API Mouse getMouse();
    JACE_PROXY_API JInt getMouseCrosshairSpriteCycleIndex();
    JACE_PROXY_API QList<Sprite> getMouseCrosshairSprites();
    JACE_PROXY_API JInt getMouseCrosshairState();
    JACE_PROXY_API JInt getNPCCombatCount();
    JACE_PROXY_API QList<JInt> getNPCCombatIndexArray();
    JACE_PROXY_API HashTable getNPCNodeCache();
    JACE_PROXY_API ObjectDefLoader getObjectDefLoader();
    JACE_PROXY_API JInt getPlane();
    JACE_PROXY_API JInt getPlayerCount();
    JACE_PROXY_API QList<JInt> getPlayerIndexArray();
    JACE_PROXY_API Cache getPlayerModels();
    JACE_PROXY_API QList<Server> getServers();
    JACE_PROXY_API JInt getSubMenuHeight();
    JACE_PROXY_API JInt getSubMenuWidth();
    JACE_PROXY_API JInt getSubMenuX();
    JACE_PROXY_API JInt getSubMenuY();
    JACE_PROXY_API QList<JFloat> getTileData();
    JACE_PROXY_API QList<JBoolean> getValidInterfaceArray();

private:
    DECLARE_FRIENDS
};

} // end namespace bridge
} // end namespace api

#endif // CLIENT_H
