#ifndef ITEMSTORAGE_H
#define ITEMSTORAGE_H

#include "node.h"

namespace world{

class ItemStorage : public Node{
private:
    Q_DISABLE_COPY(ItemStorage)
    vector<jint> ids;
    vector<jint> stacksizes;
public:
    ItemStorage();
    vector<jint> getIds(bool useCache = true);
    vector<jint> getStacksizes(bool useCache = true);
};

}

#endif // ITEMSTORAGE_H
