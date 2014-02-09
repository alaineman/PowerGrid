#ifndef CLIENT_H
#define CLIENT_H

#include "jace/os_dep.h"
#include "jace/proxy/JObject.h"

#include "jace/javacast.h"

#include "jace/JArray.h"
#include "jace/JFieldProxy.h"
#include "jace/JMethod.h"
#include "jace/JField.h"

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

class Client : virtual java::lang::Object {
public:
    JACE_PROXY_API explicit Client ();
    JACE_PROXY_API explicit Client (const Client&);

    JACE_PROXY_API virtual const RSClass* getJavaJniClass() const throw(::jace::JNIException);
    JACE_PROXY_API static const RSClass* staticGetJavaJniClass() throw(::jace::JNIException);

    JACE_PROXY_API explicit Client (jvalue);
    JACE_PROXY_API explicit Client (jobject);

    JACE_PROXY_API static Client getClient();

    JACE_PROXY_API Camera getCamera();
    JACE_PROXY_API Canvas getCanvas();
    JACE_PROXY_API java::util::Map getChatChannels();
    JACE_PROXY_API NodeSubQueue getCollapsedMenuItems();
    JACE_PROXY_API jint getConnectionState();
    JACE_PROXY_API java::lang::String getCurrentAction();
    JACE_PROXY_API QList<GrandExchangeOffer> getCurrentGrandExchangeOffers();
    JACE_PROXY_API jint getDestinationX();
    JACE_PROXY_API jint getDestinationY();
    JACE_PROXY_API DetailInfoNode getDetailInfoNode();
    JACE_PROXY_API jint getFPS();
    JACE_PROXY_API Facade getFacade();
    JACE_PROXY_API jint getFrameTime();
    JACE_PROXY_API QList<Friend> getFriendsList();
    JACE_PROXY_API GraphicsToolkit getGraphicsToolkit();
    JACE_PROXY_API QList<Interface> getInterfaceArray();
    JACE_PROXY_API QList<Rectangle> getInterfaceBoundsArray();
    JACE_PROXY_API jint getInterfaceIndex();
    JACE_PROXY_API HashTable getInterfaceNodeCache();
    JACE_PROXY_API ItemDefLoader getItemDefLoader();
    JACE_PROXY_API LandscapeInfo getLandscapeInfo();
    JACE_PROXY_API java::lang::String getLastSelectedItemName();
    JACE_PROXY_API QList<HintArrow> getLoadedHintArrows();
    JACE_PROXY_API HashTable getLoadedItems();
    JACE_PROXY_API jint getLoadedNPCCount();
    JACE_PROXY_API QList<NPCNode> getLoadedNPCNodes();
    JACE_PROXY_API QList<OverheadMessage> getLoadedOverheadMessages();
    JACE_PROXY_API QList<Player> getLoadedPlayers();
    JACE_PROXY_API Deque getLoadedProjectiles();
    JACE_PROXY_API Player getLocalPlayer();
    JACE_PROXY_API jint getLoopCycle();
    JACE_PROXY_API jint getMenuHeight();
    JACE_PROXY_API Deque getMenuItems();
    JACE_PROXY_API QList<java::lang::String> getMenuOptions();
    JACE_PROXY_API jint getMenuOptionsCount();
    JACE_PROXY_API jint getMenuOptionsCountCollapsed();
    JACE_PROXY_API jint getMenuWidth();
    JACE_PROXY_API jint getMenuX();
    JACE_PROXY_API jint getMenuY();
    JACE_PROXY_API jint getMessageCounter();
    JACE_PROXY_API jfloat getMinimapAngle();
    JACE_PROXY_API jint getMinimapOffset();
    JACE_PROXY_API jint getMinimapScale();
    JACE_PROXY_API jint getMinimapSetting();
    JACE_PROXY_API MouseListener getMouse();
    JACE_PROXY_API jint getMouseCrosshairSpriteCycleIndex();
    JACE_PROXY_API QList<Sprite> getMouseCrosshairSprites();
    JACE_PROXY_API jint getMouseCrosshairState();
    JACE_PROXY_API jint getNPCCombatCount();
    JACE_PROXY_API QList<jint> getNPCCombatIndexArray();
    JACE_PROXY_API HashTable getNPCNodeCache();
    JACE_PROXY_API ObjectDefLoader getObjectDefLoader();
    JACE_PROXY_API jint getPlane();
    JACE_PROXY_API jint getPlayerCount();
    JACE_PROXY_API QList<jint> getPlayerIndexArray();
    JACE_PROXY_API Cache getPlayerModels();
    JACE_PROXY_API QList<Server> getServers();
    JACE_PROXY_API jint getSubMenuHeight();
    JACE_PROXY_API jint getSubMenuWidth();
    JACE_PROXY_API jint getSubMenuX();
    JACE_PROXY_API jint getSubMenuY();
    JACE_PROXY_API QList<jfloat> getTileData();
    JACE_PROXY_API QList<jboolean> getValidInterfaceArray();

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
