/* 
 * File:   Core.h
 * Author: Chronio
 *
 * Created on April 22, 2013, 9:45 AM
 */
#include "jni.h"

#ifndef JAVAENV_H
#define	JAVAENV_H

namespace powergrid {
namespace reflect {
    
    /* This class provides an easy-to-use wrapper around a running Java 
     * environment.
     */
    class JavaEnv {
        /* The Java virtual machine. */
        JavaVM* jvm;
        /* The JNI environment. */
        JNIEnv* env;
    public:
        /** Destructs the JavaEnv object, terminating the JavaVM
         */
        ~JavaEnv();
        
        /** Returns the JNIEnv object referenced in this JavaEnv. */
        JNIEnv* Env();
        /** Returns the JavaVM object referenced in this JavaEnv. */
        JavaVM* JVM();
        
        /** Sets up and starts the Java VM, using the given classpath and main
         *  Class.
         */
        virtual int Setup(const char* classpath, const char* mainClass);
        /** Finds and returns the class with the given fully qualified name. 
         *  When no class with that name is found, this function returns NULL.
         */
        virtual jclass FindClass(const char* name);
        /** Finds and returns a class that uses the given annotation class.
         *  When no class with that annotation is found, this function returns NULL.
         */
        virtual jclass FindClass(jclass annotation);
        /** Finds all subclasses of the given parent class and places them in 
         *  the given jclass array. This method returns the amount of classes 
         *  found. Note that this is an expensive operation.
         */
        virtual int FindSubclasses(jclass* children, jclass parent);
        /** Gracefully terminates this Java environment. 
         */
        virtual int Terminate();
        /** Finds the method with the specified name and parameters in the 
         *  provided jclass.
         */
        virtual jmethodID FindMethod(jclass c, const char* name, const char* sig);
    };
    
} /* namespace reflect*/
} /* namespace powergrid*/

#endif	/* JAVAENV_H */

