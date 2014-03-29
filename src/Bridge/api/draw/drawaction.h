#ifndef API_DRAW_DRAWACTION_H
#define API_DRAW_DRAWACTION_H

#include <QObject>
#include <stdexcept>
#include "jni.h"

namespace java {
 namespace awt {
  class Graphics;
 }
}

namespace api {
namespace draw {

using java::awt::Graphics;

/**
 * @brief Draw function signature
 *
 * Functions with this signature can be used to draw
 * overlays.
 *
 * @param g the Java Graphics to draw with
 */
typedef void DrawFn(Graphics g);

/**
 * @brief The DrawAction class
 */
class DrawAction : public QObject {
    Q_OBJECT
private:
    DrawFn* func;
protected:
    DrawAction(QObject* parent = 0);
public:
    DrawAction(DrawFn* drawFunction, QObject* parent = 0);
    virtual ~DrawAction() throw() {}

    virtual void draw(Graphics g);
};

} // namespace draw
} // namespace api

#endif // API_DRAW_DRAWACTION_H
