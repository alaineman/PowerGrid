#include "navigator.h"

#include "rs/client.h"
#include "rs/player.h"

#include "navigation.h"

using bridge::Client;
using bridge::Player;

Navigator::Navigator() :
    _navigation(0) {
}

Vec3D Navigator::currentPosition() const {
    Player player = Client::getLocalPlayer();
    return Vec3D (player.getLocationX(),
                  player.getLocationY(),
                  player.getPlane().getByte());
}

Navigation* Navigator::findPath(Vec3D destination) {
    return findPath(currentPosition(), destination);
}

Navigation* Navigator::findPath(Vec3D origin, Vec3D destination) {
    Q_UNUSED(origin); // TODO implement path-finding algorithm
    return new Navigation(QList<Vec3D>() << destination);
}

void Navigator::move(Vec3D target) {
    // TODO implement move operation
    //      1. Translate target position to 2D based on camera coordinates
    //      2. Click the translated (2D) position
    Q_UNUSED(target)
}

void Navigator::navigate(Vec3D destination) {
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

