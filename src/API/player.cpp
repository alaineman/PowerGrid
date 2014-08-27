#include "player.h"

#include "rs/client.h"
#include "rs/animator.h"
#include "rs/playerdef.h"

#include "java/lang/string.h"

namespace API {
namespace player {

RS::Player local() {
    return RS::Client::getLocalPlayer();
}

bool isIdle() {
    return local().getActiveAnimator().isNull();
}

Gender getGender() {
    return local().getPlayerDef().isFemale() ? Female : Male;
}

QString getName() {
    return local().getName().toQString();
}

int getLevel() {
    return local().getLevel().getInt();
}

} // namespace player
} // namespace API
