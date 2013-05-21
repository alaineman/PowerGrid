#ifndef WIDGET_H
#define WIDGET_H

#include "stdafx.h"

namespace world {

  class Widget {
    private:
      unsigned short id;
      std::vector<Widget> children;
    public:
      Widget(unsigned short widget_id);

      unsigned short GetID();

      bool Visible();
  };

}
#endif // WIDGET_H
