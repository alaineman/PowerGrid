#ifndef NPC_H
#define NPC_H

#include "character.h"
#include "npccomposite.h"

namespace world{

class Npc : public Character {
private:
    Q_DISABLE_COPY(Npc)
    NpcComposite* composite;
public:
    Npc(jobject obj) : Character(obj){}
    NpcComposite* getComposite(bool useCache = true);
};

}


#endif // NPC_H
