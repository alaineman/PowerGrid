#ifndef JAVAMODEL_H
#define JAVAMODEL_H

#include "model.h"

namespace world{

class JavaModel : public Model {
private:
    Q_DISABLE_COPY(JavaModel)
public:
    JavaModel(jobject obj) : Model(obj){}
    vector<jshort> getXPoints(bool useCache = true);
    vector<jshort> getXIndices(bool useCache = true);
    vector<jshort> getYPoints(bool useCache = true);
    vector<jshort> getYIndices(bool useCache = true);
    vector<jshort> getZPoints(bool useCache = true);
    vector<jshort> getZIndices(bool useCache = true);
};

}

#endif // JAVAMODEL_H
