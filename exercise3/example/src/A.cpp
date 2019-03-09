#include "A.h"
#include<string.h>
#include<iostream>

using namespace std;

A::A() : A("", 0) {}

A::A(const A & other): A(other.getString(),other.getInt()){}

A::A(const char * string, int i)
{
	this->aString = nullptr;

	setString(string);
	setInt(i);

}

A::~A()
{
	delete[] this->aString;
}

void A::print() const
{
	cout << "String: " << getString() << endl << "Int: " << getInt() << endl;
}

void A::setString(const char * string)
{
	delete[] this->aString;

	int len = strlen(string)+1;

	this->aString = new char[len];
	strcpy_s(this->aString, len, string);
}

void A::setInt(int i)
{
	this->aInt = i;
}

const char * A::getString() const
{
	return this->aString;
}

int A::getInt() const
{
	return this->aInt;
}
