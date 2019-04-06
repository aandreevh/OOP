#include "String.h"
#include <string.h>


String::String() : String("") {}

String::String(const String & other) {
    *this = other;
}

String::String(const char * buffer) {
    *this = buffer;
}

String::~String() {
    delete[] buffer;
}


String &String::operator=(const char * other) {

    setBuffer(other);
    return *this;
}

String &String::operator=(const String & other) {

    return *this = other.buffer;
}

String String::operator+(const String & other) const {
    return (String(*this)+=other);
}

String &String::operator+=(const String & other) {

    unsigned int tempSize = getSize()+other.getSize();
    char* temp = new char[tempSize+1];
    temp[tempSize] = 0;

    for(unsigned int i=0;i<getSize();i++)
        temp[i] = buffer[i];

    for(unsigned int i=0;i<other.getSize();i++)
        temp[getSize()+i] = other.buffer[i];

    setSize(tempSize);

    delete[] buffer;
    buffer = temp;

    return *this;
}

bool String::operator==(const String & other) const {
    return strcmp(getBuffer(),other.getBuffer())==0;
}

bool String::operator!=(const String & other) const {
    return !(*this == other);
}

bool String::operator>(const String & other) const {
    return strcmp(getBuffer(),other.getBuffer()) >0;
}

bool String::operator<(const String & other) const {
    ///NB: !(*this > other) does not work
    return strcmp(getBuffer(),other.getBuffer()) <0;
}

unsigned int String::getSize() const {
    return this->size;
}

bool String::isEmpty() const {
    return getSize() ==0;
}

const char *String::getBuffer() const {
    return this->buffer;
}

void String::setBuffer(const char * other) {
    delete[] this->buffer;

    setSize(strlen(other));
    this->buffer = new char[getSize()+1];

    strcpy(this->buffer,other);

}

void String::setSize(unsigned int size) {
    this->size = size;
}

void String::setBuffer(const String & other) {
    setBuffer(other.buffer);
}

bool String::operator>=(const String & other) const {
    return (*this > other) || (*this == other);
}

bool String::operator<=(const String & other) const {
    return (*this < other) || (*this == other);
}

ostream& operator<<(ostream& output, const String& string){
    output<<string.getBuffer();

    return output;
}
istream& operator>>(istream& input, String& string){

    ///Could be smarter here

    char buffer[1024];
    input>>buffer;

    string.setBuffer(buffer);

    return input;
}


