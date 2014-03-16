#ifndef API_BRIDGE_INTERFACE_H
#define API_BRIDGE_INTERFACE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

namespace api {
namespace bridge {

class InterfaceChild;

/*!
 * \brief The Interface class
 *
 * The Interface class is basically a holder for the InterfaceChild hiarchy.
 * Jagex uses it to easily group their interfaces.
 */
class Interface : public Object {
public:
    RS_OBJECT(Interface)
    /*!
     * \brief The list of direct Children to this interface
     *
     * The first generation of Childs.
     */
    JACE_PROXY_API QList<InterfaceChild> getChildren();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_INTERFACE_H
