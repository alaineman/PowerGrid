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


namespace RS {

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
class KeyListener;
class LandscapeInfo;
class MenuGroupNode;
class HintArrow;
class NPCNode;
class OverheadMessage;
class Player;
class Deque;
class AbstractMouseListener;
class Sprite;
class ObjectDefLoader;
class Cache;
class Server;

class Client : public Object {
public:
    // Macro defining required framework methods and constructors
    RS_OBJECT(Client)

    static JACE_PROXY_API Client getClient();

    static JACE_PROXY_API Camera getCamera();
    static JACE_PROXY_API JInt getCameraPitch();
    static JACE_PROXY_API JInt getCameraYaw();
    static JACE_PROXY_API Canvas getCanvas();
    static JACE_PROXY_API java::util::Map getChatChannels();
    static JACE_PROXY_API NodeSubQueue getCollapsedMenuItems();
    static JACE_PROXY_API JInt getConnectionState();
    static JACE_PROXY_API String getCurrentAction();
    static JACE_PROXY_API MenuGroupNode getCurrentMenuGroupNode();
    static JACE_PROXY_API QList<GrandExchangeOffer> getCurrentGrandExchangeOffers();
    static JACE_PROXY_API JInt getDestinationX();
    static JACE_PROXY_API JInt getDestinationY();
    static JACE_PROXY_API DetailInfoNode getDetailInfoNode();
    static JACE_PROXY_API JInt getFPS();
    static JACE_PROXY_API Facade getFacade();
    static JACE_PROXY_API JInt getFrameTime();
    static JACE_PROXY_API QList<Friend> getFriendsList();
    static JACE_PROXY_API GraphicsToolkit getGraphicsToolkit();
    static JACE_PROXY_API QList<Interface> getInterfaceArray();
    static JACE_PROXY_API QList<java::awt::Rectangle> getInterfaceBoundsArray();
    static JACE_PROXY_API JInt getInterfaceIndex();
    static JACE_PROXY_API HashTable getInterfaceNodeCache();
    static JACE_PROXY_API ItemDefLoader getItemDefLoader();
    static JACE_PROXY_API JBoolean isItemSelected();
    static JACE_PROXY_API KeyListener getKeyboard();
    static JACE_PROXY_API LandscapeInfo getLandscapeInfo();
    static JACE_PROXY_API String getLastSelectedItemName();
    static JACE_PROXY_API QList<HintArrow> getLoadedHintArrows();
    static JACE_PROXY_API HashTable getLoadedItems();
    static JACE_PROXY_API JInt getLoadedNPCCount();
    static JACE_PROXY_API QList<NPCNode> getLoadedNPCNodes();
    static JACE_PROXY_API QList<OverheadMessage> getLoadedOverheadMessages();
    static JACE_PROXY_API QList<Player> getLoadedPlayers();
    static JACE_PROXY_API Deque getLoadedProjectiles();
    static JACE_PROXY_API Player getLocalPlayer();
    static JACE_PROXY_API JInt getLoopCycle();
    static JACE_PROXY_API JBoolean isMenuCollapsed();
    static JACE_PROXY_API JInt getMenuHeight();
    static JACE_PROXY_API Deque getMenuItems();
    static JACE_PROXY_API JBoolean isMenuOpen();
    static JACE_PROXY_API QList<String> getMenuOptions();
    static JACE_PROXY_API JInt getMenuOptionsCount();
    static JACE_PROXY_API JInt getMenuOptionsCountCollapsed();
    static JACE_PROXY_API JInt getMenuWidth();
    static JACE_PROXY_API JInt getMenuX();
    static JACE_PROXY_API JInt getMenuY();
    static JACE_PROXY_API JInt getMessageCounter();
    static JACE_PROXY_API JFloat getMinimapAngle();
    static JACE_PROXY_API JInt getMinimapOffset();
    static JACE_PROXY_API JInt getMinimapScale();
    static JACE_PROXY_API JInt getMinimapSetting();
    static JACE_PROXY_API AbstractMouseListener getMouse();
    static JACE_PROXY_API JInt getMouseCrosshairSpriteCycleIndex();
    static JACE_PROXY_API QList<Sprite> getMouseCrosshairSprites();
    static JACE_PROXY_API JInt getMouseCrosshairState();
    static JACE_PROXY_API JInt getNPCCombatCount();
    static JACE_PROXY_API QList<JInt> getNPCCombatIndexArray();
    static JACE_PROXY_API QList<JInt> getNPCIndexArray();
    static JACE_PROXY_API HashTable getNPCNodeCache();
    static JACE_PROXY_API ObjectDefLoader getObjectDefLoader();
    static JACE_PROXY_API JInt getPlane();
    static JACE_PROXY_API JInt getPlayerCount();
    static JACE_PROXY_API QList<JInt> getPlayerIndexArray();
    static JACE_PROXY_API Cache getPlayerModels();
    static JACE_PROXY_API QList<Server> getServers();
    static JACE_PROXY_API JBoolean isSpellSelected();
    static JACE_PROXY_API JInt getSubMenuHeight();
    static JACE_PROXY_API JInt getSubMenuWidth();
    static JACE_PROXY_API JInt getSubMenuX();
    static JACE_PROXY_API JInt getSubMenuY();
    static JACE_PROXY_API QList<JFloat> getTileData();
    static JACE_PROXY_API QList<JBoolean> getValidInterfaceArray();

private:
    DECLARE_FRIENDS
};

} // end namespace bridge

#endif // CLIENT_H
