#ifndef JNIEVENT_H
#define JNIEVENT_H

#include <QtCore>

namespace jni {

  /**
   * @brief Enum that defines the different JNI event types.
   */
  enum JNIEventType {
    JNIStarted,
    JNIStopped
  };

  /**
   * @brief QEvent subclass for dispatching events from the JNI module
   */
  class JNIEvent : public QEvent {
    private:
      JNIEventType type;
      QString description;
    public:
      static const QEvent::Type typeID = static_cast<QEvent::Type>(1337);

      /**
       * @brief Creates a JNIEvent with the specified type and an optional description
       * @param t the type of the JNIEvent
       * @param desc a QString describing the cause for this JNIEvent (optional)
       */
      explicit JNIEvent(JNIEventType t, QString desc = QString()) : QEvent(typeID){
        type = t;
        description = desc;
      }

      /**
       * @brief Returns the specific JNI Event type
       * @return the specific JNI Event type
       */
      JNIEventType JNIType() { return type; }
      /**
       * @brief Returns the description for this JNIEvent
       * @return a description of the cause for this JNIEvent
       */
      QString Desc() { return description; }


  };

}

#endif // JNIEVENT_H
