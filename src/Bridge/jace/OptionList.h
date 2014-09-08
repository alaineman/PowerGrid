#ifndef JACE_OPTION_LIST_H
#define JACE_OPTION_LIST_H

#include "os_dep.h"
#include "JNIException.h"
#include "counted_ptr.h"

#include <jni.h>

#include <vector>
#include <string>

namespace jace {

/**
 * A Jvm option. These are supplied to jace::helper::createVm()
 * in an OptionList.
 *
 * @author Toby Reyelts
 *
 */
class Option {

  public:

  JACE_API virtual ~Option() {}

  /**
   * Returns the text string value of the option.
   * For example, "-Djava.class.path=c:\foo\myclasses"
   *
   */
  JACE_API virtual std::string stringValue() = 0;

  /**
   * Returns the extra data required for an option,
   * for example, a pointer to a vfprintf hook.
   * Returns NULL if no extra data is required.
   *
   */
  JACE_API virtual void* extraInfo() = 0;

  /**
   * Returns a dynamically allocated copy of the Option.
   *
   */
  JACE_API virtual Option* clone() const = 0;
};

/**
 * A List of Options. An OptionList is supplied to jace::helper::createVm()
 * to specify the set of virtual machine options to be used in creating
 * a virtual machine.
 *
 */
class OptionList {

  public:

  typedef ::jace::counted_ptr<Option> OptionPtr;

  /**
   * An OptionList iterator.
   *
   */
  class iterator {  

    public:

    JACE_API iterator( std::vector<OptionPtr>::iterator it_ );
    JACE_API iterator operator++();
    JACE_API iterator operator++( int i );
    JACE_API iterator operator--();
    JACE_API iterator operator--( int i );
    JACE_API OptionPtr operator*();
    JACE_API bool operator!=( const iterator& it_ );


    private:
    std::vector<OptionPtr>::iterator it;
  };

  /**
   * Creates a new empty OptionList.
   *
   */
  JACE_API OptionList();

  /**
   * Adds a clone of option to the list.
   *
   */
  JACE_API void push_back( const Option& option );

  /**
   * Returns the size of the list.
   *
   */
  JACE_API size_t size() const;

  /**
   * Returns an iterator to the beginning of the list.
   *
   */
  JACE_API iterator begin() const;
 
  /**
   * Returns an iterator to the beginning of the list.
   *
   */
  JACE_API iterator end() const;

  /**
   * Returns the OptionList as an array of JNI options.
   *
   * The caller must deallocate the options by making a call
   * to destroyJniOptions().
   *
   */
  JACE_API JavaVMOption* createJniOptions() const;

  /**
   * Releases the options created by a call to createJniOptions().
   *
   */
  JACE_API void destroyJniOptions( JavaVMOption* jniOptions ) const;


  private:
  mutable std::vector<OptionPtr> options;
};

/**
 * A specific type of Option, the SystemProperty tells the
 * virtual machine to set the named system property to the
 * specified value.
 *
 */
class SystemProperty : public Option {
  private:
    std::string mName;
    std::string mValue;
  public:

  /**
   * Creates a new SystemProperty with the specified name and value.
   *
   */
  JACE_API SystemProperty( const std::string& name_, const std::string& value_ );
  
  /**
   * Returns the name of the SystemProperty.
   *
   */
  JACE_API virtual std::string name();
  
  /**
   * Returns the value of the SystemProperty.
   *
   */
  JACE_API virtual std::string value();

  JACE_API virtual std::string stringValue();
  JACE_API virtual void* extraInfo();
  JACE_API virtual Option* clone() const;
};


//-------------------------------------------------------------------------
// Predefined Option instances
//-------------------------------------------------------------------------

class ClassPath : public SystemProperty {
public:
    JACE_API ClassPath( const std::string& value )
        : SystemProperty( "java.class.path", value ) {}
};

class LibraryPath : public SystemProperty {
public:
    JACE_API LibraryPath( const std::string& value )
        : SystemProperty( "java.library.path", value ) {}
};

class JavaAgent : public Option {
private:
    std::string value;
public:
    JACE_API JavaAgent( const std::string& path ) : value(path) {}
    JACE_API virtual std::string stringValue() { return "-javaagent:"+value; }
    JACE_API virtual void* extraInfo() { return 0; }
    JACE_API virtual Option* clone() const { return new JavaAgent(value); }
};

/**
 * A virtual machine specific, custom option.
 *
 * You may specify any virtual machine specific option, for example,
 * "-Xmx=128M". All custom options must begin with a leading
 * "-X" or "_" string.
 *
 */
class CustomOption : public Option {

  public:

  JACE_API CustomOption( const std::string& value_ );

  JACE_API virtual std::string stringValue();
  JACE_API virtual void* extraInfo();
  JACE_API virtual Option* clone() const;

  private:
  std::string value;
};

}

#endif // JACE_OPTION_LIST_H

