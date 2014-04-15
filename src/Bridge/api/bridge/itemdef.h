#ifndef API_BRIDGE_ITEMDEF_H
#define API_BRIDGE_ITEMDEF_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;

// Forward declarations of Java API classes
namespace java {
 namespace lang {
  class String;
 }
}

namespace api {
namespace bridge {

class HashTable;
class ItemDefLoader;

/*!
 * \brief The ItemDef contains pivotal information on the Item.
 *
 * The ItemDef (item definition) is linked to the actual Item with the ID.
 * It can also be linked to InterfaceChild components with the ID.
 *
 */
class ItemDef : public Object {
public:
    RS_OBJECT(ItemDef)

    /*!
     * \brief The actions that can be performed on/with this Item.
     */
    JACE_PROXY_API QList<String> getActions();


    JACE_PROXY_API QList<String> getGroundActions();

    /*!
     * \brief The ID corresponding to this Item.
     */
    JACE_PROXY_API JInt getID();

    /*!
     * \brief Retrieves the ItemDefLoader corresponding with the Item.
     */
    JACE_PROXY_API ItemDefLoader getItemDefLoader();

    JACE_PROXY_API JBoolean isMembers();
    /*!
     * \brief The name the Item.
     *
     * When playing on a german or spanish server the name of the Item
     * usually differs to the normal English servers.
     *
     * The language can be found in the ItemDefLoader
     *
     */
    JACE_PROXY_API String getName();
    JACE_PROXY_API HashTable getNodeTable();
private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_ITEMDEF_H
