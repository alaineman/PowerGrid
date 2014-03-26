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
#include "landscapeinfo.h"
#include "hintarrow.h"
#include "npcnode.h"
#include "overheadmessage.h"
#include "player.h"
#include "deque.h"
#include "mouse.h"
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

// Client::getClient() needs special attention since it's static.
// Also see jace/RSClassMapper.h
//Client Client::getClient() {
//    JNIEnv* env = jace::helper::attach();
//    RSClassMapper* rscm = RSClassMapper::DefaultInstance();
//    QString clsName = rscm->getStaticFieldClass("getClient");
//    std::string fldName = rscm->getStaticFieldName("getClient").toStdString();
//    jclass cls = rscm->getClass(clsName);
//    if (cls == NULL) {
//        throw jace::JNIException("static class: " + clsName);
//    }
//    jfieldID field = env->GetStaticFieldID(cls, fldName.c_str(), "Lclient;");
//    if (field == 0) {
//        throw jace::JNIException("static field " + fldName);
//    }
//    jobject obj = env->GetStaticObjectField(cls, field);
//    Client result (obj);
//    return result;
//}
IMPL_STATIC_OBJECT_FIELD(Client, getClient, Client)

// virtual fields, organized by first character
IMPL_OBJECT_METHOD(Client, getCamera, Camera)
IMPL_OBJECT_METHOD(Client, getCanvas, Canvas)
IMPL_OBJECT_METHOD(Client, getChatChannels, java::util::Map)
IMPL_OBJECT_METHOD(Client, getCollapsedMenuItems, NodeSubQueue)
IMPL_PRIMITIVE_METHOD(Client, getConnectionState, JInt)
IMPL_OBJECT_METHOD(Client, getCurrentAction, String)
IMPL_ARRAY_METHOD(Client, getCurrentGrandExchangeOffers, GrandExchangeOffer)

IMPL_PRIMITIVE_METHOD(Client, getDestinationX, JInt)
IMPL_PRIMITIVE_METHOD(Client, getDestinationY, JInt)
IMPL_OBJECT_METHOD(Client, getDetailInfoNode, DetailInfoNode)

//IMPL_PRIMITIVE_METHOD(Client, getFPS, JInt)
IMPL_STATIC_INT_FIELD(Client, getFPS)

IMPL_OBJECT_METHOD(Client, getFacade, Facade)
IMPL_PRIMITIVE_METHOD(Client, getFrameTime, JInt)
IMPL_ARRAY_METHOD(Client, getFriendsList, Friend)

IMPL_OBJECT_METHOD(Client, getGraphicsToolkit, GraphicsToolkit)

IMPL_ARRAY_METHOD(Client, getInterfaceArray, Interface)
IMPL_ARRAY_METHOD(Client, getInterfaceBoundsArray, java::awt::Rectangle)
IMPL_PRIMITIVE_METHOD(Client, getInterfaceIndex, JInt)
IMPL_OBJECT_METHOD(Client, getInterfaceNodeCache, HashTable)
IMPL_OBJECT_METHOD(Client, getItemDefLoader, ItemDefLoader)

IMPL_OBJECT_METHOD(Client, getLandscapeInfo, LandscapeInfo)
IMPL_OBJECT_METHOD(Client, getLastSelectedItemName, String)
IMPL_ARRAY_METHOD(Client, getLoadedHintArrows, HintArrow)
IMPL_OBJECT_METHOD(Client, getLoadedItems, HashTable)
IMPL_PRIMITIVE_METHOD(Client, getLoadedNPCCount, JInt)
IMPL_ARRAY_METHOD(Client, getLoadedNPCNodes, NPCNode)
IMPL_ARRAY_METHOD(Client, getLoadedOverheadMessages, OverheadMessage)
IMPL_ARRAY_METHOD(Client, getLoadedPlayers, Player)
IMPL_OBJECT_METHOD(Client, getLoadedProjectiles, Deque)
IMPL_OBJECT_METHOD(Client, getLocalPlayer, Player)
IMPL_PRIMITIVE_METHOD(Client, getLoopCycle, JInt)

IMPL_PRIMITIVE_METHOD(Client, getMenuHeight, JInt)
IMPL_ARRAY_METHOD(Client, getMenuOptions, String)
IMPL_PRIMITIVE_METHOD(Client, getMenuOptionsCount, JInt)
IMPL_PRIMITIVE_METHOD(Client, getMenuOptionsCountCollapsed, JInt)
IMPL_PRIMITIVE_METHOD(Client, getMenuWidth, JInt)
IMPL_PRIMITIVE_METHOD(Client, getMenuX, JInt)
IMPL_PRIMITIVE_METHOD(Client, getMenuY, JInt)
IMPL_PRIMITIVE_METHOD(Client, getMessageCounter, JInt)
IMPL_PRIMITIVE_METHOD(Client, getMinimapAngle, JFloat)
IMPL_PRIMITIVE_METHOD(Client, getMinimapOffset, JInt)
IMPL_PRIMITIVE_METHOD(Client, getMinimapScale, JInt)
IMPL_PRIMITIVE_METHOD(Client, getMinimapSetting, JInt)
IMPL_OBJECT_METHOD(Client, getMouse, Mouse)
IMPL_PRIMITIVE_METHOD(Client, getMouseCrosshairSpriteCycleIndex, JInt)
IMPL_ARRAY_METHOD(Client, getMouseCrosshairSprites, Sprite)
IMPL_PRIMITIVE_METHOD(Client, getMouseCrosshairState, JInt)

IMPL_PRIMITIVE_METHOD(Client, getNPCCombatCount, JInt)
IMPL_ARRAY_METHOD(Client, getNPCCombatIndexArray, JInt)
IMPL_OBJECT_METHOD(Client, getNPCNodeCache, HashTable)

IMPL_OBJECT_METHOD(Client, getObjectDefLoader, ObjectDefLoader)

IMPL_PRIMITIVE_METHOD(Client, getPlane, JInt)
IMPL_PRIMITIVE_METHOD(Client, getPlayerCount, JInt)
IMPL_ARRAY_METHOD(Client, getPlayerIndexArray, JInt)
IMPL_OBJECT_METHOD(Client, getPlayerModels, Cache)

IMPL_ARRAY_METHOD(Client, getServers, Server)
IMPL_PRIMITIVE_METHOD(Client, getSubMenuHeight, JInt)
IMPL_PRIMITIVE_METHOD(Client, getSubMenuWidth, JInt)
IMPL_PRIMITIVE_METHOD(Client, getSubMenuX, JInt)
IMPL_PRIMITIVE_METHOD(Client, getSubMenuY, JInt)

IMPL_ARRAY_METHOD(Client, getTileData, JFloat)

IMPL_ARRAY_METHOD(Client, getValidInterfaceArray, JBoolean)

} // end namespace bridge
} // end namespace api
