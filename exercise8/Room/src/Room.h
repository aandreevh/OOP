#ifndef UNTITLED_ROOM_H
#define UNTITLED_ROOM_H

#include "Object.h"

class Room{

    Object* objects = nullptr;
    unsigned int size =0;

    double maxWeight=0;


    void incrementSize();
    void decrementSize();

    void resize();

public:

    Room();
    Room(double);
    Room(const Room&);
    ~Room();

    Room& operator=(const Room &);

    bool add(const Object&);
    void remove(unsigned int);

    bool setMaxWeight(double);

    void clean();

    Object operator[](unsigned int)const;
    unsigned int getSize() const;
    bool isEmpty() const;

    double getMaxWeight() const;
    double getCurrentWeight() const;

};

#endif //UNTITLED_ROOM_H
