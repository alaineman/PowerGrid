#ifndef CLIENT_H
#define CLIENT_H

#include "jace/os_dep.h"
#include "jace/proxy/JObject.h"

#include "jace/javacast.h"

#include "jace/JArray.h"
#include "jace/JFieldProxy.h"
#include "jace/JMethod.h"
#include "jace/JField.h"

using namespace jace::proxy::types;

#include "RSClass.h"

#include "java/lang/object.h"

#include <QList>

// Forward declarations of Java API classes
namespace java {
 namespace lang {
  class String;
 }
 namespace util {
  class Map;
 }
}

namespace api {
namespace native {

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
class Rectangle;
class HashTable;
class ItemDefLoader;
class LandscapeInfo;
class HintArrow;
class NPCNode;
class OverheadMessage;
class Player;
class Deque;
class MouseListener;
class Sprite;
class ObjectDefLoader;
class Cache;
class Server;

class Client : public virtual java::lang::Object {
public:
    JACE_PROXY_API Client (const Client& obj);

    JACE_PROXY_API virtual const RSClass* getJavaJniClass() const throw(::jace::JNIException);
    JACE_PROXY_API static const RSClass* staticGetJavaJniClass() throw(::jace::JNIException);

    JACE_PROXY_API explicit Client (jvalue);
    JACE_PROXY_API explicit Client (jobject);

    JACE_PROXY_API static Client getClient();

    JACE_PROXY_API Camera getCamera();
    JACE_PROXY_API Canvas getCanvas();
    JACE_PROXY_API java::util::Map getChatChannels();
    JACE_PROXY_API NodeSubQueue getCollapsedMenuItems();
    JACE_PROXY_API JInt getConnectionState();
    JACE_PROXY_API java::lang::String getCurrentAction();
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
    JACE_PROXY_API QList<Rectangle> getInterfaceBoundsArray();
    JACE_PROXY_API JInt getInterfaceIndex();
    JACE_PROXY_API HashTable getInterfaceNodeCache();
    JACE_PROXY_API ItemDefLoader getItemDefLoader();
    JACE_PROXY_API LandscapeInfo getLandscapeInfo();
    JACE_PROXY_API java::lang::String getLastSelectedItemName();
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
    JACE_PROXY_API QList<java::lang::String> getMenuOptions();
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
    JACE_PROXY_API MouseListener getMouse();
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
    // Needed for casting objects of this type
    template <typename T> friend T (jace::java_cast)(const ::jace::proxy::JObject&);

    // Needed to integrate this class into the JACE framework
    template <typename T> friend class jace::ElementProxy;
    template <typename T> friend class jace::JFieldProxy;
    template <typename T> friend class jace::JMethod;
};

} // end namespace native
} // end namespace api

namespace jace {

template <> class ElementProxy<api::native::Client> {
public:
    ElementProxy (jarray array, jvalue element, int _index);
    ElementProxy (const ElementProxy<api::native::Client>& proxy);
private:
    jarray parent;
    int mIndex;
};

template <> class JFieldProxy<api::native::Client> {
    JFieldProxy(jfieldID _fieldID, jvalue value, jobject _parent);
    JFieldProxy(jfieldID _fieldID, jvalue value, jclass _parentClass);
    JFieldProxy(api::native::Client& object);
private:
    jobject parent;
    jclass parentClass;
    jfieldID fieldID;
};

}

#endif // CLIENT_H
