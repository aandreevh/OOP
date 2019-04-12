#include "Room.h"


void Room::incrementSize() {
    this->size++;
}

void Room::decrementSize() {
    this->size--;
}

void Room::resize() {
    Object* temp = new Object[getSize()+1];

    for(unsigned int i=0;i<getSize();i++){
        temp[i]= objects[i];
    }

    delete[] objects;
    objects = temp;
    incrementSize();
}

Room::Room():Room(0) {}

Room::Room(double w) {
    setMaxWeight(w);
}

Room::Room(const Room & other) {
    *this = other;
}

Room::~Room() {
    delete[] objects;
}

Room &Room::operator=(const Room & other) {
    if(this == &other) return *this;

    clean();
    setMaxWeight(other.getMaxWeight());

    for(unsigned int i =0;i<other.getSize();i++){
        add(other[i]);
    }

    return *this;
}

void Room::clean() {
    delete[] this->objects;
    this->objects = nullptr;
    this->size = 0;

}

bool Room::add(const Object & other) {
    if(other.getWeight() > getMaxWeight() - getCurrentWeight())return false;

    resize();
    this->objects[getSize()-1] = other;

    return true;
}

void Room::remove(unsigned int index) {
    if(index >= getSize()) return;

    decrementSize();

    for(unsigned int i=index;i<getSize();i++){
        objects[i] = objects[i+1];
    }

}

bool Room::setMaxWeight(double nw) {
    if(nw < getCurrentWeight()) return false;

    this->maxWeight = nw;

    return true;
}

Object Room::operator[](unsigned int index) const {
    ///? Error
    if(index >= getSize()) return Object();


    return objects[index];
}

unsigned int Room::getSize() const {
    return this->size;
}

bool Room::isEmpty() const {
    return getSize() == 0;
}

double Room::getMaxWeight() const {
    return this->maxWeight;
}

double Room::getCurrentWeight() const {

    double  w = 0;

    for(unsigned int i=0;i<getSize();i++) {
        w+= (*this)[i].getWeight();
    }

    return w;
}
