#include "IntegerArray.h"

unsigned int IntegerArray::getCapacity() const
{
	return this->capacity;
}

bool IntegerArray::resizeCapacity(unsigned int capacity)
{
	if (getCapacity() >= capacity) {
		return false;
	} 
	
	this->capacity = capacity;

	int *narr = new int[getCapacity()];

	for (unsigned int i = 0; i < getSize(); i++) {
		narr[i] = array[i];
	}

	delete[] array;

	array = narr;

	return true;
}

void IntegerArray::incrementCapacity()
{
	if (getCapacity() == 0) {
		resizeCapacity(1);
	}
	else {
		resizeCapacity(getCapacity() * 2);
	}
}

void IntegerArray::incrementSize()
{
	if (getSize() == getCapacity()) {
		incrementCapacity();
	}

	this->size++;
}

void IntegerArray::decrementSize()
{
	if (!isEmpty()) {
		this->size--;
	}
}

IntegerArray::IntegerArray() {}

IntegerArray::IntegerArray(const IntegerArray & other)
{
	for (unsigned int i = 0; i < other.getSize(); i++) {
		this->addInteger(other.getInteger(i));
	}
}

IntegerArray::~IntegerArray()
{
	delete[] array;
}

void IntegerArray::addInteger(int val)
{
	incrementSize();
	array[getSize() - 1] = val;
}

bool IntegerArray::removeInteger(unsigned int index)
{
	if (getSize() <= index) return false;

		for (unsigned int i = index; i < getSize() - 1; i++) {
			array[i] = array[i + 1];
		}

		decrementSize();

		return true;
	
}

void IntegerArray::setInteger(int val, unsigned int index)
{
	if (index == getSize()) { 
		addInteger(val);
	}
	else {
		array[index] = val;
	}
}

int IntegerArray::getInteger(unsigned int index) const
{
	if (index < getSize()) {
		return array[index];
	}

	//Error ?
}

unsigned int IntegerArray::getSize() const
{
	return this->size;
}

bool IntegerArray::isEmpty() const
{
	return getSize()==0;
}
