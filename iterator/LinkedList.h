
#ifndef TI_LINKEDLIST_H
#define TI_LINKEDLIST_H

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include "RandomAccessIterator.h"
#include "Iterable.h"

#include "Node.h"


template<class T>
class DoubleLinkedList : public Iterable< BidirectionalIterator<T,NodeItr<T> > > {



   Node<T> * head,*tail;

    std::size_t size;

    void incrementSize() {
        this->size++;
    }

    void decrementSize(){
        this->size--;
    }

public:

    DoubleLinkedList():head(nullptr),tail(nullptr),size(0){}
    DoubleLinkedList(const DoubleLinkedList<T>& o):DoubleLinkedList<T>(){
        *this = o;
    }

    DoubleLinkedList(std::initializer_list<T> elements):DoubleLinkedList(){
        for(auto e : elements)add(e);
    }

    DoubleLinkedList<T>& operator=(const DoubleLinkedList<T>& other){

        for(auto it = other.begin(); it != other.end();++it)add(*it);

        return *this;
    }

    void add(const T& element){
        insert(element,getSize());
    }

    bool insert(const T& element, std::size_t position){
        if(position > getSize())return false;

        if(isEmpty()) head = tail = new Node<T>(element,nullptr,nullptr);
        else if(position ==0){ //head
            head = new Node<T>(element,nullptr,head);
            head->prev->next = head;
        }else if (position == getSize()){ //tail
            tail = new Node<T>(element,tail,nullptr);
            tail->next->prev = tail;
        }
        else{
            Node<T>* n = head->operator-(position);

            n = new Node<T>(element,n->next,n);
            n->next->prev = n;
            n->prev->next = n;
        }

        incrementSize();
        return true;
    }

    bool remove(std::size_t position){
        if(position > getSize()) return false;
        if(head==tail){
            delete head;
            head=tail=nullptr;
        }else if(position == 0){
            Node<T>* temp = head;
            head = head->prev;
            head->next = nullptr;
            delete temp;
        }else if(position == getSize()-1){
            Node<T>* temp = tail;
            tail = tail->next;
            tail->prev = nullptr;
            delete temp;
        }
        else{
            Node<T>* n = head->operator-(position);
            n->prev->next = n->next;
            n->next->prev = n->prev;
        }

        decrementSize();
        return true;
    }

    T& get(std::size_t position){
        if(position > getSize()) throw std::invalid_argument("Position out of bounds");

        return (head->operator-(position))->data;
    }
    const T& get(std::size_t position) const{
        if(position > getSize()) throw std::invalid_argument("Position out of bounds");

        return (head->operator-(position))->data;
    }

    T &operator[](std::size_t position) {
        return get(position);
    }

    const T &operator[](std::size_t position) const {
        return get(position);
    }


    bool isEmpty() const{
        return getSize() == 0;
    }

    std::size_t getSize() const{
        return this->size;
    }


    friend std::ostream& operator<<(std::ostream& o, DoubleLinkedList<T>& list ){
        Node<T>* node = list.head;

        while(node != nullptr){
            std::cout<<node->data<<" ";
            node = node->prev;
        }

        return o;
    }

    BidirectionalIterator<T,NodeItr<T> > begin() {
        return RandomAccessIterator<T,NodeItr<T> >(NodeItr<T>(head));
    }
    BidirectionalIterator<T,NodeItr<T> > end() {
        return RandomAccessIterator<T,NodeItr<T> >(NodeItr<T>((Node<T>*)nullptr));
    }
    BidirectionalIterator<T,NodeItr<T> > last() {
        return RandomAccessIterator<T,NodeItr<T> >(NodeItr<T>(tail));
    }


};


#endif //TI_LINKEDLIST_H
