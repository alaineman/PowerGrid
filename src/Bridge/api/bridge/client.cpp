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

// Include the class header and the MethodHelper
#include "client.h"
#include "MethodHelper.h"

// Don't forget to include the types of the fields (if they're not primitive)
#include "java/lang/string.h"
#include "java/util/map.h"
#include "java/awt/rectangle.h"
#include "camera.h"
#include "canvas.h"
#include "nodesubqueue.h"
#include "grandexchangeoffer.h"
#include "detailinfonode.h"
#include "facade.h"
#include "friend.h"
#include "graphicstoolkit.h"
#include "interface.h"
#include "hashtable.h"
#include "itemdefloader.h"
#include "keylistener.h"
#include "landscapeinfo.h"
#include "hintarrow.h"
#include "menugroupnode.h"
#include "npcnode.h"
#include "overheadmessage.h"
#include "player.h"
#include "deque.h"
#include "mouselistener.h"
#include "sprite.h"
#include "objectdefloader.h"
#include "cache.h"
#include "server.h"

#include "jace/RSClassMapper.h"

// Work in the correct namespace (api::native for all RS proxies)
namespace api {
namespace bridge {

using jace::RSClassMapper;

// framework macros (required for all proxy classes)
IMPL_JACE_CONSTRUCTORS(Client)
IMPL_RSCLASS_GET(Client)

IMPL_STATIC_OBJECT_FIELD(Client, getCamera, Camera)
IMPL_STATIC_FLOAT_FIELD(Client, getCameraPitch)
IMPL_STATIC_FLOAT_FIELD(Client, getCameraYaw)
IMPL_STATIC_OBJECT_FIELD(Client, getCanvas, Canvas)
IMPL_STATIC_OBJECT_FIELD(Client, getChatChannels, java::util::Map)
IMPL_STATIC_OBJECT_FIELD(Client, getClient, Client)
IMPL_STATIC_OBJECT_FIELD(Client, getCollapsedMenuItems, NodeSubQueue)
IMPL_STATIC_INT_FIELD(Client, getConnectionState)
IMPL_STATIC_OBJECT_FIELD(Client, getCurrentAction, String)
IMPL_ARRAY_METHOD(Client, getCurrentGrandExchangeOffers, GrandExchangeOffer)
IMPL_STATIC_OBJECT_FIELD(Client, getCurrentMenuGroupNode, MenuGroupNode)

IMPL_STATIC_INT_FIELD(Client, getDestinationX)
IMPL_STATIC_INT_FIELD(Client, getDestinationY)
IMPL_STATIC_OBJECT_FIELD(Client, getDetailInfoNode, DetailInfoNode)

IMPL_STATIC_INT_FIELD(Client, getFPS)

IMPL_STATIC_OBJECT_FIELD(Client, getFacade, Facade)
IMPL_STATIC_INT_FIELD(Client, getFrameTime)
IMPL_ARRAY_METHOD(Client, getFriendsList, Friend)

IMPL_STATIC_OBJECT_FIELD(Client, getGraphicsToolkit, GraphicsToolkit)

IMPL_ARRAY_METHOD(Client, getInterfaceArray, Interface)
IMPL_ARRAY_METHOD(Client, getInterfaceBoundsArray, java::awt::Rectangle)
IMPL_STATIC_INT_FIELD(Client, getInterfaceIndex)
IMPL_STATIC_OBJECT_FIELD(Client, getInterfaceNodeCache, HashTable)
IMPL_STATIC_OBJECT_FIELD(Client, getItemDefLoader, ItemDefLoader)

IMPL_STATIC_OBJECT_FIELD(Client, getKeyboard, KeyListener)

IMPL_STATIC_OBJECT_FIELD(Client, getLandscapeInfo, LandscapeInfo)
IMPL_STATIC_OBJECT_FIELD(Client, getLastSelectedItemName, String)
IMPL_ARRAY_METHOD(Client, getLoadedHintArrows, HintArrow)
IMPL_STATIC_OBJECT_FIELD(Client, getLoadedItems, HashTable)
IMPL_STATIC_INT_FIELD(Client, getLoadedNPCCount)
IMPL_ARRAY_METHOD(Client, getLoadedNPCNodes, NPCNode)
IMPL_ARRAY_METHOD(Client, getLoadedOverheadMessages, OverheadMessage)
IMPL_ARRAY_METHOD(Client, getLoadedPlayers, Player)
IMPL_STATIC_OBJECT_FIELD(Client, getLoadedProjectiles, Deque)
IMPL_STATIC_OBJECT_FIELD(Client, getLocalPlayer, Player)
IMPL_STATIC_INT_FIELD(Client, getLoopCycle)

IMPL_STATIC_BOOLEAN_FIELD(Client, isMenuCollapsed)
IMPL_STATIC_INT_FIELD(Client, getMenuHeight)
IMPL_STATIC_BOOLEAN_FIELD(Client, isMenuOpen)
IMPL_ARRAY_METHOD(Client, getMenuOptions, String)
IMPL_STATIC_INT_FIELD(Client, getMenuOptionsCount)
IMPL_STATIC_INT_FIELD(Client, getMenuOptionsCountCollapsed)
IMPL_STATIC_INT_FIELD(Client, getMenuWidth)
IMPL_STATIC_INT_FIELD(Client, getMenuX)
IMPL_STATIC_INT_FIELD(Client, getMenuY)
IMPL_STATIC_INT_FIELD(Client, getMessageCounter)
IMPL_STATIC_FLOAT_FIELD(Client, getMinimapAngle)
IMPL_STATIC_INT_FIELD(Client, getMinimapOffset)
IMPL_STATIC_INT_FIELD(Client, getMinimapScale)
IMPL_STATIC_INT_FIELD(Client, getMinimapSetting)
IMPL_STATIC_OBJECT_FIELD(Client, getMouse, MouseListener)
IMPL_STATIC_INT_FIELD(Client, getMouseCrosshairSpriteCycleIndex)
IMPL_ARRAY_METHOD(Client, getMouseCrosshairSprites, Sprite)
IMPL_STATIC_INT_FIELD(Client, getMouseCrosshairState)

IMPL_STATIC_INT_FIELD(Client, getNPCCombatCount)
IMPL_ARRAY_METHOD(Client, getNPCCombatIndexArray, JInt)
IMPL_ARRAY_METHOD(Client, getNPCIndexArray, JInt)
IMPL_STATIC_OBJECT_FIELD(Client, getNPCNodeCache, HashTable)

IMPL_STATIC_OBJECT_FIELD(Client, getObjectDefLoader, ObjectDefLoader)

IMPL_STATIC_INT_FIELD(Client, getPlane)
IMPL_STATIC_INT_FIELD(Client, getPlayerCount)
IMPL_ARRAY_METHOD(Client, getPlayerIndexArray, JInt)
IMPL_STATIC_OBJECT_FIELD(Client, getPlayerModels, Cache)

IMPL_ARRAY_METHOD(Client, getServers, Server)
IMPL_STATIC_BOOLEAN_FIELD(Client, isSpellSelected)
IMPL_STATIC_INT_FIELD(Client, getSubMenuHeight)
IMPL_STATIC_INT_FIELD(Client, getSubMenuWidth)
IMPL_STATIC_INT_FIELD(Client, getSubMenuX)
IMPL_STATIC_INT_FIELD(Client, getSubMenuY)

IMPL_ARRAY_METHOD(Client, getTileData, JFloat)

IMPL_ARRAY_METHOD(Client, getValidInterfaceArray, JBoolean)

} // end namespace bridge
} // end namespace api
