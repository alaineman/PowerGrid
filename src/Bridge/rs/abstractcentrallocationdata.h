#ifndef ABSTRACTCENTRALLOCATIONDATA_H
#define ABSTRACTCENTRALLOCATIONDATA_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace RS {

/*!
 * \brief Abstract version of the CentralLocationData class.
 */
class AbstractCentralLocationData : public Object {
public:
    RS_OBJECT(AbstractCentralLocationData)
private:
    DECLARE_FRIENDS
};

}

#endif // ABSTRACTCENTRALLOCATIONDATA_H
