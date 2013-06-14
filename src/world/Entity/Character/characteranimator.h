#ifndef CHARACTERANIMATOR_H
#define CHARACTERANIMATOR_H

#include "character.h"
#include "Entity/animator.h"

namespace world{

class CharacterAnimator : public Animator {
private:
    Q_DISABLE_COPY(CharacterAnimator)
    Character* animating;
public:
    CharacterAnimator(jobject obj) : Animator(obj){}
    Character* getAnimating(bool useCache = true);
};

}

#endif // CHARACTERANIMATOR_H
