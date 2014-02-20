#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class AbstractModel : public Object {
public:
    RS_OBJECT(AbstractModel)
private:
    DECLARE_FRIENDS
};

}
}
#endif // ABSTRACTMODEL_H
