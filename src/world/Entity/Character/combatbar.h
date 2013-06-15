#ifndef COMBATBAR_H
#define COMBATBAR_H

#include "DataStructure/linkedlistnode.h"
#include "DataStructure/linkedlist.h"

namespace world{

class CombatBar : public LinkedListNode {
private:
    Q_DISABLE_COPY(CombatBar)
    LinkedList* list;
public:
    CombatBar(jobject obj) : LinkedListNode(obj){}
    LinkedList* getList(bool useCache = true);
};

}

#endif // COMBATBAR_H
