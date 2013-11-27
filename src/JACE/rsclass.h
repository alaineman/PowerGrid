#ifndef RSCLASS_H
#define RSCLASS_H
#include "jace/os_dep.h"
#include "jace/namespace.h"
#include "jace/JClassImpl.h"
#include "jace/JNIException.h"

#include <string>

class RSClass : public ::jace::JClassImpl {
  private:
    std::string simpleName;
  public:
    JACE_API RSClass(const std::string name, const std::string simpleName);
    JACE_API virtual ~RSClass() throw();

    JACE_API virtual const std::string& getSimpleName() const;
};

#endif // RSCLASS_H
