#ifndef JAVAMODEL_H
#define JAVAMODEL_H

#include "model.h"

namespace world{

class JavaModel : public Model {
private:
    Q_DISABLE_COPY(JavaModel)
public:
    JavaModel(jobject obj) : Model(obj){}
};

}

#endif // JAVAMODEL_H
