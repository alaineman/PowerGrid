#include "client.h"

#include "MethodHelper.h"

namespace api {
namespace native {

JACE_PROXY_API Client::Client(const Client& obj) :
    JObject(NoOp()), Object(obj) {
}

JACE_PROXY_API Client::Client(jobject obj) {
    setJavaJniObject(obj);
}

JACE_PROXY_API Client::Client(jvalue val) {
    setJavaJniValue(val);
}

JACE_PROXY_API Client& Client::operator =(Client& other) {
    setJavaJniObject(other.getJavaJniObject());
    return *this;
}

IMPL_RSCLASS_GET(Client)

IMPL_STATIC_OBJECT_METHOD(Client, getClient, Client)

IMPL_PRIMITIVE_METHOD(Client, getConnectionState, JInt)
IMPL_PRIMITIVE_METHOD(Client, getDestinationX, JInt)
IMPL_PRIMITIVE_METHOD(Client, getDestinationY, JInt)
IMPL_PRIMITIVE_METHOD(Client, getFPS, JInt)
IMPL_PRIMITIVE_METHOD(Client, getFrameTime, JInt)
IMPL_PRIMITIVE_METHOD(Client, getInterfaceIndex, JInt)
IMPL_PRIMITIVE_METHOD(Client, getLoadedNPCCount, JInt)
IMPL_PRIMITIVE_METHOD(Client, getLoopCycle, JInt)
IMPL_PRIMITIVE_METHOD(Client, getMenuHeight, JInt)
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
IMPL_PRIMITIVE_METHOD(Client, getMouseCrosshairSpriteCycleIndex, JInt)
IMPL_PRIMITIVE_METHOD(Client, getMouseCrosshairState, JInt)
IMPL_PRIMITIVE_METHOD(Client, getNPCCombatCount, JInt)
IMPL_PRIMITIVE_METHOD(Client, getPlane, JInt)
IMPL_PRIMITIVE_METHOD(Client, getPlayerCount, JInt)
IMPL_ARRAY_METHOD(Client, getPlayerIndexArray, JInt)
IMPL_PRIMITIVE_METHOD(Client, getSubMenuHeight, JInt)
IMPL_PRIMITIVE_METHOD(Client, getSubMenuWidth, JInt)
IMPL_PRIMITIVE_METHOD(Client, getSubMenuX, JInt)
IMPL_PRIMITIVE_METHOD(Client, getSubMenuY, JInt)
IMPL_ARRAY_METHOD(Client, getTileData, JFloat)
IMPL_ARRAY_METHOD(Client, getValidInterfaceArray, JBoolean)

} // end namespace native
} // end namespace api
