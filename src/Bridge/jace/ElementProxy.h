#ifndef JACE_ELEMENT_PROXY_H
#define JACE_ELEMENT_PROXY_H

#include "jace/os_dep.h"
#include "jace/JNIHelper.h"
#include "jace/proxy/JObject.h"
#include "jace/JClass.h"

#include "jace/proxy/types/JBoolean.h"
#include "jace/proxy/types/JByte.h"
#include "jace/proxy/types/JChar.h"
#include "jace/proxy/types/JDouble.h"
#include "jace/proxy/types/JFloat.h"
#include "jace/proxy/types/JInt.h"
#include "jace/proxy/types/JLong.h"
#include "jace/proxy/types/JShort.h"
using namespace jace::proxy::types;

namespace jace {

/**
 * An ElementProxy is a wrapper around a JArray element.
 *
 * An ElementProxy is responsible for pinning and depinning
 * its element as required.
 *
 * @author Toby Reyelts
 *
 */
template <class ElementType> class ElementProxy :
        public ElementType, public virtual proxy::JObject {
public:

    /**
     * Creates a new ElementProxy that belongs to the given array.
     *
     * This constructor shouldn't be called anymore, as it should be specialized
     * by every proxy type. Every ElementProxy instance should allocate
     * a new global ref to its parent array.
     *
     *
     */
    ElementProxy( jarray array, jvalue element, int index ) :
        ElementType( element ), proxy::JObject( NO_OP ),
        parent( array ), mIndex( index ) {

        std::cout << "ElementProxy was not properly specialized for " <<
                     ElementType::staticGetJavaJniClass()->getName() << std::endl;
    }

    /**
     * Copy constructor. This constructor should also never be called. It should be specialized away.
     *
     */
    ElementProxy( const ElementProxy& proxy ) : proxy::JObject( NO_OP ), ElementType( 0 ), parent( proxy.parent ), mIndex( proxy.mIndex ) {
        std::cout << "ElementProxy was not properly specialized for " <<
                     ElementType::staticGetJavaJniClass()->getName() << std::endl;
    }

    /**
     * If someone assigns to this array element, they're really assigning
     * to an array, so we need to call SetObjectArrayElement.
     *
     */
    ElementType& operator=( const ElementType& element ) {
        JNIEnv* env = helper::attach();
        jobjectArray array = static_cast<jobjectArray>(parent);
        jobject val = element.getJavaJniObject();
        env->SetObjectArrayElement(array, mIndex, val);
        return *this;
    }

    /**
     * If someone assigns to this array element, they're really assigning
     * to an array, so we need to call SetObjectArrayElement.
     *
     */
    const ElementType& operator=( const ElementType& element ) const {
        JNIEnv* env = helper::attach();
        jobjectArray array = static_cast<jobjectArray>(parent);
        jobject val = element.getJavaJniObject();
        env->SetObjectArrayElement(array, mIndex, val);
        return *this;
    }

    ~ElementProxy() throw() {
        try {
            JNIEnv* env = helper::attach();
            helper::deleteGlobalRef( env, parent );
        } catch ( std::exception& e ) {
            Q_UNUSED(e);
        }
    }

private:
    jarray parent;
    int mIndex;
};

// ----------------------------------------------------------
// Template specializations for the jace::ElementProxy class
// ----------------------------------------------------------

template <> class ElementProxy<JBoolean> : public JBoolean {
public:
    ElementProxy(jarray array, jvalue element, int index);
    JBoolean& operator= (const JBoolean element);
private:
    jarray parent;
    int mIndex;
};

template <> class ElementProxy<JByte> : public JByte {
public:
    ElementProxy(jarray array, jvalue element, int index);
    JByte& operator= (const JByte element);
private:
    jarray parent;
    int mIndex;
};

template <> class ElementProxy<JChar> : public JChar {
public:
    ElementProxy(jarray array, jvalue element, int index);
    JChar& operator= (const JChar element);
private:
    jarray parent;
    int mIndex;
};

template <> class ElementProxy<JDouble> : public JDouble {
public:
    ElementProxy(jarray array, jvalue element, int index);
    JDouble& operator= (const JDouble element);
private:
    jarray parent;
    int mIndex;
};

template <> class ElementProxy<JFloat> : public JFloat {
public:
    ElementProxy(jarray array, jvalue element, int index);
    JFloat& operator= (const JFloat element);
private:
    jarray parent;
    int mIndex;
};

template <> class ElementProxy<JInt> : public JInt {
public:
    ElementProxy(jarray array, jvalue element, int index);
    JInt& operator= (const JInt element);
private:
    jarray parent;
    int mIndex;
};

template <> class ElementProxy<JLong> : public JLong {
public:
    ElementProxy(jarray array, jvalue element, int index);
    JLong& operator= (const JLong element);
private:
    jarray parent;
    int mIndex;
};

template <> class ElementProxy<JShort> : public JShort {
public:
    ElementProxy(jarray array, jvalue element, int index);
    JShort& operator= (const JShort element);
private:
    jarray parent;
    int mIndex;
};

}

#endif

