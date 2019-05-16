
#ifndef TI_NODE_H
#define TI_NODE_H

#include <cstddef>


template <typename T>
struct Node{
    Node* next,*prev;
    T data;
    Node():next(nullptr),prev(nullptr){}
    Node(const T& _data, Node* _next,  Node* _prev):data(_data),next(_next),prev(_prev){}

    Node*operator+(std::size_t count) const{
        Node* cur = (Node*)this;

        while(count != 0) {
            cur = cur->next;
            count--;
        }

        return cur;
    }

    Node*operator-(std::size_t count) const{
        Node* cur = (Node*)this;

        while(count !=0){
            cur = cur->prev;
            count--;
        }

        return cur;
    }

};

template <typename T>
struct NodeItr{

    Node<T>* cur;

    NodeItr():cur(nullptr){}
    NodeItr(Node<T>* cur){
        this->cur = cur;
    }
    NodeItr(const NodeItr<T>* itr){
        this->cur = itr->cur;
    }

    NodeItr<T>&operator=(const NodeItr<T>& itr){
        this->cur = itr.cur;

        return *this;
    }

    NodeItr<T>&operator+(std::size_t mv){
        cur = cur->operator-(mv);

        return *this;
    }

    NodeItr<T>&operator-(std::size_t mv){
        cur = cur->operator+(mv);

        return *this;
    }

    bool operator==(const NodeItr<T>& itr) const{
        return this->cur == itr.cur;
    }

    T& operator*() const{
        return cur->data;
    }

    T&operator[](long long mv){
        if(mv <0) return this->cur->operator+((std::size_t)(-mv))->data;

        return this->cur->operator-((std::size_t )mv)->data;
    }


};

#endif //TI_NODE_H
