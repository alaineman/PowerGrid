#include "navigator.h"

#include "rs/client.h"
#include "rs/player.h"

#include "navigation.h"

using component::Position;

using RS::Client;
using RS::Player;

Navigator::Navigator() :
    _navigation(0) {
}

Position *Navigator::currentPosition() const {
    Player player = Client::getLocalPlayer();
    return Position* (player.getLocationX(),
                  player.getLocationY(),
                  player.getPlane().getByte());
}

Navigation* Navigator::findPath(Position* destination) {
    return findPath(currentPosition(), destination);
}

Navigation* Navigator::findPath(Position* origin, Position* destination) {
    Q_UNUSED(origin); // TODO implement path-finding algorithm
    return new Navigation(QList<Position*>() << destination);
}

void Navigator::move(Position* target) {
    // TODO implement move operation
    //      1. Translate target position to 2D based on camera coordinates
    //      2. Click the translated (2D) position
    Q_UNUSED(target)
}

void Navigator::navigate(Position* destination) {
    navigate(findPath(destination));
}

void Navigator::navigate(Navigation *navigation) {
    Q_ASSERT_X(navigation, "Navigator::navigate", "Navigation is NULL");
    _navigation = navigation;
    navigation->reset();
    emit started(navigation);
    move(navigation->next());
}

void Navigator::updateState() {
    // TODO if still busy, do nothing
    //      else:
    emit reached(_navigation->current());
    move(_navigation->next());
}

