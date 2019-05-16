#ifndef TI_DYNAMICARRAY_H
#define TI_DYNAMICARRAY_H


#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "Iterable.h"
#include "RandomAccessIterator.h"

template<class T>
class DynamicArray : public Iterable<RandomAccessIterator<T> >{

    T *data;
    std::size_t size;
    std::size_t capacity;

    std::size_t getCapacity() const {
        return this->capacity;
    }

    void increaseCapacity(std::size_t amount) {

        if (amount == 0)return;

        this->capacity += amount;

        T *temp = new T[capacity];

        for (std::size_t i = 0; i < getSize(); i++)
            temp[i] = this->data[i];

        delete[] data;

        this->data = temp;

    }

    bool isFull() const {
        return getSize() == getCapacity();
    }

    void resize() {
        if (getCapacity() == 0)increaseCapacity(1);
        else increaseCapacity(getCapacity());
    }

    void incrementSize() {
        if (isFull()) resize();
        this->size++;
    }

    void decrementSize() {
        if (getSize() > 0)this->size--;
    }

public:


    DynamicArray() : data(nullptr), size(0), capacity(0) {}


    DynamicArray(std::initializer_list<T> elements):DynamicArray(){
        for(auto e : elements)add(e);
    }


    DynamicArray(const DynamicArray<T> &other) : DynamicArray<T>::DynamicArray() {
        *this = other;
    }

    DynamicArray(int n) : DynamicArray<T>::DynamicArray() {
        for (auto i = 0; i < n; i++)add(T());
    }


    ~DynamicArray() {
        delete[] this->data;
    }


    DynamicArray<T> &operator=(const DynamicArray<T> &other) {

        if (this == &other) return *this;

        clean();
        for (std::size_t i = 0; i < other.getSize(); i++) add(other[i]);

        return *this;
    }

    void clean() {
        while (!isEmpty())remove(getSize() - 1);
    }

    bool insert(const T &element, std::size_t position) {

        if (position > getSize()) return false;

        incrementSize();

        for (std::size_t i = getSize() - 1; i > position; i--)
            data[i] = data[i - 1];

        data[position] = element;

        return true;
    }

    bool remove(std::size_t position) {
        if (position >= getSize()) return false;

        for (std::size_t i = position; i < getSize() - 1; i++)
            data[i] = data[i + 1];

        decrementSize();

        return true;
    }

    const T &get(std::size_t position) const {
        if (position > getSize()) throw std::invalid_argument("Position out of bounds.");

        return data[position];
    }

    T &get(std::size_t position) {
        if (position > getSize()) throw std::invalid_argument("Position out of bounds.");

        return data[position];
    }

    void add(const T &element) {
        insert(element, getSize());
    }

    T &operator[](std::size_t position) {
        return get(position);
    }

    const T &operator[](std::size_t position) const {
        return get(position);
    }


    DynamicArray<T> &operator+=(const T &element) {

        add(element);
        return *this;
    }


    std::size_t getSize() const {
        return this->size;
    }

    bool isEmpty() const {
        return getSize() == 0;
    }

    RandomAccessIterator<T> begin(){
        return Iterator<T>(data);
    }

    RandomAccessIterator<T> end(){
        return Iterator<T>(data+getSize());
    }

    RandomAccessIterator<T> last(){
        return Iterator<T>(data+getSize()-1);
    }


};

template<typename T>
std::ostream &operator<<(std::ostream &output, const DynamicArray<T> &array) {

    for (std::size_t i = 0; i < array.getSize(); i++)output << array[i] << " ";

    return output;
}


#endif //TI_DYNAMICARRAY_H
