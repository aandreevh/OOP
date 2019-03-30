#ifndef STACKPROJECT_STACK_H
#define STACKPROJECT_STACK_H

struct Node{
    Node* prev;
    int value;

    Node(Node* prev,int value){
        this->prev = prev;
        this->value = value;
    }
};
class Stack{

    Node* head;
    int size;

    void decrementSize();
    void incrementSize();

public:

    Stack();
    Stack(const Stack&);
    ~Stack();

    void push(int);
    int pop();

    int peek() const;

    int getSize() const;
    bool isEmpty() const;

    //debug
    void print() const;


};


#endif //STACKPROJECT_STACK_H
