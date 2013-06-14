#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity/animableentity.h"
#include "DataStructure/linkedlist.h"
#include "Entity/animator.h"
#include "overheadmessage.h"

namespace world {

class CharacterAnimator;

class Character : public AnimableEntity {
private:
    Q_DISABLE_COPY(Character)
    jint height;
    jint orientation;
    jint interactingEntityIndex;
    OverheadMessage* overheadMessage;
    Animator* primaryAnimator;
    CharacterAnimator* secondaryAnimator;
    LinkedList* combatBarList;
public:
    Character(jobject obj) : AnimableEntity(obj) {}
    jint getHeight(bool useCache = true);
    jint getOrientation(bool useCache = true);
    jint getInteractingEntityIndex(bool useCache = true);
    OverheadMessage* getOverheadMessage(bool useCache = true);
    Animator* getPrimaryAnimator(bool useCache = true);
    CharacterAnimator* getSecondaryAnimator(bool useCache = true);
    LinkedList* getCombatBarList(bool useCache = true);
};

}

#endif // CHARACTER_H
