#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "playercomposite.h"
#include "jnistring.h"

namespace world{

class Player : public Character {
private:
    Q_DISABLE_COPY(Player)    
    jbyte gender;
    jint totallevel;
    jint f2pcombatlevel;
    jint p2pcombatlevel;
    jint wildernessdepth;
    jni::JNIString* title;
    jni::JNIString* name;
    PlayerComposite* composite;
public:
    Player(jobject obj) : Character(obj) {}
    jbyte getGender(bool useCache = true);    
    jint getTotalLevel(bool useCache = true);
    jint getF2PCombatLevel(bool useCache = true);
    jint getP2PCombatLevel(bool useCache = true);
    jint getWildernessDepth(bool useCache = true);
    jni::JNIString* getTitle(bool useCache = true);
    jni::JNIString* getName(bool useCache = true);
    PlayerComposite* getComposite(bool useCache = true);
};

}

#endif // PLAYER_H
