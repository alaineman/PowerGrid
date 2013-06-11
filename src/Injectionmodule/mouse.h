#ifndef MOUSE_H
#define MOUSE_H
#include <QObject>
#include "point.h"

using namespace world;

namespace injection{

enum MouseButton{
    LeftButton, RightButton, MiddleButton
};

enum ScrollWheel{
    Up, Down
};

class Mouse : public QObject {
private:
    Q_DISABLE_COPY(Mouse)
    static Mouse* mouse;
    Mouse();
public:    
    static Mouse* instance() { return (mouse == NULL ? mouse = new Mouse() : mouse); }
    Point getPosition();
    bool isDown(MouseButton button = LeftButton);
    void move(Point position);
    void click(MouseButton button = LeftButton);
    void drag(Point position, MouseButton button = LeftButton);
    void scroll(ScrollWheel direction = Down);
    void mouseDown(MouseButton button = LeftButton);
    void mouseUp(MouseButton button = LeftButton);
};

}
#endif // MOUSE_H
