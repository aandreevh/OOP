#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H


/**https://github.com/aandreevh/OOP/tree/master/exercise4/IntegerArray**/
#include "IntegerArray.h"

class ArrayStack{

    IntegerArray array;

public:

    ArrayStack();
    ArrayStack(const ArrayStack&);


    void push(int);
    int pop();

    int peek() const;

    unsigned int getSize() const;
    bool isEmpty() const;

};


#endif //FRACTION_ARRAYSTACK_H
