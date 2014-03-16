#ifndef API_COMPONENT_SIZE_H
#define API_COMPONENT_SIZE_H

#include "entity/component.h"
#include "jace/JField.h"

using entity::Component;
using jace::JField;

namespace api {
namespace component {

class Size : public Component {
    Q_OBJECT
private:
    JField<JInt> x, y;
public:
    explicit Size(Object ref, JField<JInt> width, JField<JInt> height, QObject* parent = NULL);
    int getWidth();
    int getHeight();
};

} // namespace component
} // namespace api

#endif // API_COMPONENT_SIZE_H
