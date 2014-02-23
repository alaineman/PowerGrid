#ifndef API_BRIDGE_GZIPDECOMPRESSOR_H
#define API_BRIDGE_GZIPDECOMPRESSOR_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace java {
 namespace util {
  namespace zip {
   class Inflater;
  }
 }
}

namespace api {
namespace bridge {

class GZIPDecompressor : public Object {
public:
    RS_OBJECT(GZIPDecompressor)

    JACE_PROXY_API java::util::zip::Inflater getInflater();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_GZIPDECOMPRESSOR_H
