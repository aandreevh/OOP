#ifndef UNTITLED_OBJECT_H
#define UNTITLED_OBJECT_H

#include<iostream>
using namespace std;

class Object{
char *name=nullptr;
char* color = nullptr;

double weight,cost;

public:


    Object();
    Object(const char*,const char*,double, double);
    Object(const Object&);
    ~Object();


    Object& operator=(const Object&);

    bool operator==(const Object&) const;
    bool operator!=(const Object&) const;

    bool operator>(const Object&) const;
    bool operator<(const Object&) const;

    void setName(const char*);
    void setColor(const char*);
    void setWeight(double);
    void setCost(double);

    const char* getName() const;
    const char* getColor() const;
    double getWeight() const;
    double getCost() const;

    friend ostream& operator<<(ostream&,const Object&);
    friend istream&operator>>(istream&, Object&);

};


#endif //UNTITLED_OBJECT_H
