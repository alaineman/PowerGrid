#ifndef ABSTRACTCAMERALOCATIONDATA_H
#define ABSTRACTCAMERALOCATIONDATA_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class AbstractCameraLocationData : public Object {
public:
    RS_OBJECT(AbstractCameraLocationData)
private:
    DECLARE_FRIENDS
};

}
}
#endif // ABSTRACTCAMERALOCATIONDATA_H
