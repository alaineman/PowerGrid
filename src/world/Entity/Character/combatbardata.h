#ifndef COMBATBARDATA_H
#define COMBATBARDATA_H

#include "DataStructure/linkedlistnode.h"

namespace world{

class CombatBarData : public LinkedListNode {
private:
    Q_DISABLE_COPY(CombatBarData)
    jint ratio;
public:
    CombatBarData(jobject obj) : LinkedListNode(obj){}
    jint getRatio(bool useCache = true);
};

}

#endif // COMBATBARDATA_H
