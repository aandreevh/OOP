#include "Object.h"
#include<iostream>
#include <string.h>
using namespace std;


#define MAX_LEN 1024


Object::Object() : Object("","",0,0) {}

Object::Object(const char * name, const char * color, double weight, double cost) {
    setName(name);
    setColor(color);
    setWeight(weight);
    setCost(cost);
}

Object::Object(const Object & o){
    *this = o;
}

Object::~Object() {
    delete[] name;
    delete[] color;
}

Object& Object::operator=(const Object & o) {

    setName(o.name);
    setColor(o.color);
    setWeight(o.weight);
    setCost(o.cost);

    return *this;
}

bool Object::operator==(const Object & o) const {
    return getCost() == o.getCost();
}

bool Object::operator!=(const Object & o) const {
    return getCost() != o.getCost();
}

bool Object::operator>(const Object & o) const {
    return getCost() > o.getCost();
}

bool Object::operator<(const Object & o) const {
    return getCost() < o.getCost();
}

void Object::setName(const char * name) {
    if(name == nullptr || name == getName()) return;

    delete[] this->name;

    unsigned long long len = strlen(name)+1;
    this->name = new char[len];
    strcpy(this->name,name);

}

void Object::setColor(const char * color) {
    if(color == nullptr || color == getColor()) return;

    delete[] this->color;

    unsigned long long len = strlen(color)+1;
    this->color = new char[len];
    strcpy(this->color,color);

}

void Object::setWeight(double weight) {
    this->weight = weight;
}

void Object::setCost(double cost) {
    this->cost = cost;
}

const char *Object::getName() const {
    return this->name;
}

const char *Object::getColor() const {
    return this->color;
}

double Object::getWeight() const {
    return this->weight;
}

double Object::getCost() const {
    return this->cost;
}

ostream& operator<<(ostream& out,const Object& o){
    out<<"Name: "<<o.getName()<<endl
    <<"Color: "<<o.getColor()<<endl
    <<"Weight: "<<o.getWeight()<<endl
    <<"Cost: "<<o.getCost();

    return out;
}

istream&operator>>(istream& in, Object& o){

    char buffer[MAX_LEN];
    double val;

    in>>buffer;
    o.setName(buffer);

    in>>buffer;
    o.setColor(buffer);

    in>>val;
    o.setWeight(val);

    in>>val;
    o.setCost(val);

    return in;
}