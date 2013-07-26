#ifndef RSOBJECT_H
#define RSOBJECT_H

#include <QObject>
#include "rsclass.h"
#include "jni.h"

class RSObject : public QObject {
    Q_OBJECT
  private:
    Q_DISABLE_COPY(RSObject)

    jobject objectRef;
    RSClass type;
  public:

    /**
     * @brief RSObject constructor
     * @param o the java object this RSObject references
     * @param c the class ID of the java object
     * @param parent the parent of this QObject
     */
    explicit RSObject(jobject o, RSClass c = NONE, QObject *parent = 0);
    
    virtual ~RSObject();

    /// returns the RSClass type of this RSObject
    RSClass getType() { return type; }
    /// returns the java object reference this RSObject holds
    jobject getObjectRef() { return objectRef; }

  protected:
    static void registerClass(RSClass cls, const char* name);
    void registerField(int fieldID, const char* fieldname);
};

#endif // RSOBJECT_H
