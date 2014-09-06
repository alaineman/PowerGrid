#ifndef ABSTRACTSERVER_H
#define ABSTRACTSERVER_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace RS {
/*!
 * \brief Abstract version of the \c Server class.
 */
class AbstractServer : public Object {
public:
    RS_OBJECT(AbstractServer)

    /*!
     * \brief descriptive flag for the \c AbstractServer.
     * \internal Needs details.
     */
    JACE_PROXY_API JInt getFlag();
private:
    DECLARE_FRIENDS
};

}
#endif // ABSTRACTSERVER_H
