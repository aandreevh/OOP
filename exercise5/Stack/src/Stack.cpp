#include "Stack.h"
#include <iostream>

using namespace std;


void copyStack(Stack& stack,Node* node){
    if(node == nullptr) return;
    copyStack(stack,node->prev);

    stack.push(node->value);
}

Stack::Stack() {
    head = nullptr;
    size = 0;
}

Stack::Stack(const Stack & stack):Stack() {

    copyStack(*this,stack.head);

}

Stack::~Stack() {
    while(!isEmpty()) pop();
}

void Stack::push(int value) {

 head= new Node(head,value);
 incrementSize();

}

int Stack::pop() {

    if(!isEmpty()){

        int value = head->value;
        Node* temp = head->prev;

        delete head;
        head = temp;

        decrementSize();

        return value;
    }
}

int Stack::peek() const {
    if(!isEmpty()){
        return head->value;
    }
}

int Stack::getSize() const {
    return this->size;
}

bool Stack::isEmpty() const {
    return this->size == 0;
}

void Stack::print() const {
    Node* cur = head;

    while(cur != nullptr){

        cout<<cur->value<<" ";

        cur = cur->prev;
    }

    cout<<endl;
}

void Stack::decrementSize() {
    this->size--;
}

void Stack::incrementSize() {
    this->size++;
}
