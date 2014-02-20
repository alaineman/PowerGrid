#ifndef API_BRIDGE_FILEWORKER_H
#define API_BRIDGE_FILEWORKER_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class FileWorker : public Object {
public:
    RS_OBJECT(FileWorker)
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_FILEWORKER_H
