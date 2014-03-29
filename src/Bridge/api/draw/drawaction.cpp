#include "drawaction.h"

namespace api {
namespace draw {

using java::awt::Graphics;

DrawAction::DrawAction(QObject *parent) : QObject(parent),
    func( 0 ) {
}

DrawAction::DrawAction(DrawFn *drawFunction, QObject* parent) :
    QObject(parent), func(drawFunction) {
    if (func == NULL) {
        throw std::invalid_argument("NULL draw function not allowed");
    }
}

void DrawAction::draw(Graphics g) {
    if (func) {
        func(g);
    } else {
        throw std::logic_error(
            "Expected either valid DrawFn or override of "
            "DrawAction::draw(Graphics), but got neither");
    }
}

} // namespace draw
} // namespace api
