#include "ArrayStack.h"

ArrayStack::ArrayStack() {

}

ArrayStack::ArrayStack(const ArrayStack & other) {
 for(unsigned int i=0;i<other.array.getSize();i++){
     array.addInteger(other.array.getInteger(i));
 }
}

void ArrayStack::push(int a) {
    array.addInteger(a);
}

int ArrayStack::pop() {
    //? size = 0

    int out = array.getInteger(array.getSize()-1);
    array.removeInteger(array.getSize()-1);

    return out;
}

int ArrayStack::peek() const {
    return array.getInteger(array.getSize()-1);
}

unsigned int ArrayStack::getSize() const {
    return array.getSize();
}

bool ArrayStack::isEmpty() const {
    return array.isEmpty();
}