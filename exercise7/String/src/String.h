//
// Created by hykar on 06.04.19.
//

#ifndef FRACTION_STRING_H
#define FRACTION_STRING_H


#include <iostream>
using namespace std;

class String{

    char* buffer=nullptr;
    unsigned int size=0;

    void setSize(unsigned int);
public:

    String();
    String(const String&);
    String(const char*);
    ~String();

    String& operator=(const String&);
    String&operator=(const char*);

    String operator+(const String&) const;
    String& operator+=(const String&);

    bool operator==(const String&) const;
    bool operator!=(const String&) const;
    bool operator>(const String&)const;
    bool operator<(const String&)const;
    bool operator>=(const String&)const;
    bool operator<=(const String&)const;


    unsigned int getSize()const;
    bool isEmpty() const;

    const char* getBuffer() const;
    void setBuffer(const char*);
    void setBuffer(const String&);

    friend ostream& operator<<(ostream&, const String&);
    friend istream& operator>>(istream&, String&);


};


#endif //FRACTION_STRING_H
