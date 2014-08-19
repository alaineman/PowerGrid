#ifndef API_BRIDGE_HASHTABLEITERATOR_H
#define API_BRIDGE_HASHTABLEITERATOR_H

#include "MethodHelper.h"
#include "java/lang/object.h"
using namespace java::lang;


namespace RS {

class Node;
class HashTable;

class HashTableIterator : public Object {
public:
    RS_OBJECT(HashTableIterator)

    /*!
     * \brief Returns the current Node in the HashTable
     * \return the current HashTable Node
     */
    JACE_PROXY_API Node getCurrent();
    /*!
     * \brief Returns the previous Node in the HashTable
     * \return the previous HashTable Node
     */
    JACE_PROXY_API Node getPrevious();
    /*!
     * \brief The HashTable associated with this iterator
     * \return the HashTable this HashTableIterator iterates over
     */
    JACE_PROXY_API HashTable getTable();
private:
    DECLARE_FRIENDS
};

} // namespace bridge

#endif // API_BRIDGE_HASHTABLEITERATOR_H
