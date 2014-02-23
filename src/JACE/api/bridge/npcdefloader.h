#ifndef API_BRIDGE_NPCDEFLOADER_H
#define API_BRIDGE_NPCDEFLOADER_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class Cache;
class NPCDefLoader : public Object {
public:
    RS_OBJECT(NPCDefLoader)

    JACE_PROXY_API Cache getDefCache();
    JACE_PROXY_API Cache getDialogModelCache();
    JACE_PROXY_API Cache getModelCache();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_NPCDEFLOADER_H
