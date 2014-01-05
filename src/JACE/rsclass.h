#ifndef RSCLASS_H
#define RSCLASS_H

#include "jace/os_dep.h"
#include "jace/namespace.h"
#include "jace/JClassImpl.h"
#include "jace/JNIException.h"

#include <string>
using std::string;

class RSClass : public jace::JClassImpl {
  private:
    string simpleName;
  public:
    JACE_API RSClass(const string name, const string simpleName);
    JACE_API virtual ~RSClass() throw() {}

    JACE_API virtual const string& getSimpleName() const;
};

#endif // RSCLASS_H
