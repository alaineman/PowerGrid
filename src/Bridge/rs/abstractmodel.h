#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace RS {

/*!
 * @brief Superclass of all models
 *
 * This class acts as the superclass for the specific model types
 * used by the 3D backend.
 */
class AbstractModel : public Object {
public:
    RS_OBJECT(AbstractModel)
private:
    DECLARE_FRIENDS
};

}

#endif // ABSTRACTMODEL_H
