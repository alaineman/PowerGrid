#ifndef ANIMABLENODE_H
#define ANIMABLENODE_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class Animable;

/*!
 * \brief Node element containing an Animable
 *
 * Contrary to what the name might suggest, this is not a Node subclass.
 * Instead, the \c AnimableNode class represents a single-linked list
 * of \c Animable objects.
 *
 */
class AnimableNode : public Object {
public:
    RS_OBJECT(AnimableNode)

    /*!
     * \brief Returns the Animable in this AnimableNode
     * \return the Animable
     */
    JACE_PROXY_API Animable getAnimable();
    /*!
     * \brief Returns the next AnimableNode in the sequence
     * \return the next AnimableNode
     */
    JACE_PROXY_API AnimableNode getNext();
private:
    DECLARE_FRIENDS
};

}
#endif // ANIMABLENODE_H
