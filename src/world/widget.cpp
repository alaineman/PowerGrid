#include "widget.h"

namespace world {

  Widget::Widget(unsigned short widget_id) {
    id = widget_id;
  }

  unsigned short Widget::GetID() {
    return id;
  }

  bool Visible() {
    return false;
  }
}
