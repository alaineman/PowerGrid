#ifndef API_BRIDGE_KEYDATA_H
#define API_BRIDGE_KEYDATA_H

#include "MethodHelper.h"

#include "java/lang/object.h"
using namespace java::lang;



namespace RS {

/**
 * \brief The KeyData class
 */
class KeyData : public Object {
public:
    RS_OBJECT(KeyData)

    /**
     * \brief Returns the character corresponding to this KeyData
     * \return the java character of this KeyData
     */
    JACE_PROXY_API JChar getCharacter();

    /**
     * \brief Returns the Unicode code point of this Key event
     * \return the Unicode code point
     */
    JACE_PROXY_API JInt getCode();

    /**
     * \brief Returns the time the event occurred.
     *
     * The time corresponds to the amount of milliseconds, as given by (java code):
     *     System.currentTimeMillis();
     *
     * \return the time the event occurred.
     */
    JACE_PROXY_API JLong getTime();

    /**
     * \brief Returns type of Key event that occurred.
     * \return the type of Key event that occurred.
     */
    JACE_PROXY_API JInt getType();

private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_KEYDATA_H
