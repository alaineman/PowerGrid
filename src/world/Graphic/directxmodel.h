#ifndef DIRECTXMODEL_H
#define DIRECTXMODEL_H

#include "model.h"

namespace world{

class DirectXModel : public Model {
private:
    Q_DISABLE_COPY(DirectXModel)
public:
    DirectXModel(jobject obj) : Model(obj){}
};

}
#endif // DIRECTXMODEL_H
