#include "keyboard.h"


namespace injection {

Keyboard* Keyboard::keyboard = NULL;

Keyboard::Keyboard(){
}

vector<Key> Keyboard::findKeyDown(){
    qWarning("calling unimplemented method");
    return vector<Key>();
}

bool Keyboard::isKeyDown(Key key){
    qWarning("calling unimplemented method");
    return false;
}

void Keyboard::typeKey(Key key){
    qWarning("calling unimplemented method");
}

void Keyboard::keyPress(Key key){
    qWarning("calling unimplemented method");
}

void Keyboard::keyRelease(Key key){
    qWarning("calling unimplemented method");
}

void Keyboard::typeChar(char c){
    qWarning("calling unimplemented method");
}

void Keyboard::typeString(const char* string){
    qWarning("calling unimplemented method");
}

}
