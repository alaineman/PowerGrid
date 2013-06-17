#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity/animableentity.h"
#include "DataStructure/linkedlist.h"
#include "Entity/animator.h"
#include "chatmessage.h"

namespace world {

class CharacterAnimator;

class Character : public AnimableEntity {
private:
    Q_DISABLE_COPY(Character)
    jint speed;
    jint height;
    jint orientation;
    jint interactingEntityIndex;
    ChatMessage* chatMessage;
    Animator* primaryAnimator;
    CharacterAnimator* secondaryAnimator;
    LinkedList* combatBarList;
public:
    Character(jobject obj) : AnimableEntity(obj) {}
    jint getCharacterSpeed(bool useCache = true);
    jint getHeight(bool useCache = true);
    jint getOrientation(bool useCache = true);
    jint getInteractingEntityIndex(bool useCache = true);
    ChatMessage* getOverheadMessage(bool useCache = true);
    Animator* getPrimaryAnimator(bool useCache = true);
    CharacterAnimator* getSecondaryAnimator(bool useCache = true);
    LinkedList* getCombatBarList(bool useCache = true);
};

}

#endif // CHARACTER_H
