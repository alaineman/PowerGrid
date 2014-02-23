#include "gzipdecompressor.h"
#include "java/util/zip/inflater.h"

namespace api {
namespace bridge {

IMPL_JACE_CONSTRUCTORS(GZIPDecompressor)
IMPL_RSCLASS_GET(GZIPDecompressor)

IMPL_OBJECT_METHOD(GZIPDecompressor, getInflater, java::util::zip::Inflater)

} // namespace bridge
} // namespace api
