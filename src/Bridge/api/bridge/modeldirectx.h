#ifndef API_BRIDGE_MODELDIRECTX_H
#define API_BRIDGE_MODELDIRECTX_H

#include "MethodHelper.h"
#include "abstractmodel.h"
using namespace java::lang;


namespace api {
namespace bridge {

class ModelDirectX : public AbstractModel {
public:
    RS_OBJECT(ModelDirectX)

private:
    DECLARE_FRIENDS
};

} // namespace bridge
} // namespace api

#endif // API_BRIDGE_MODELDIRECTX_H
