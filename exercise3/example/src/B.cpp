#include "B.h"
#include<iostream>

using namespace std;

B::B()  {


}

B::B(const B & other)
{
	setA(other.getA());
}

void B::print() const
{
	cout << "B: "<<endl;
	getA().print();
	cout << endl;

}

void B::setA(const A & a)
{
	this->a.setString(a.getString());
	this->a.setInt(a.getInt());
}


A B::getA() const
{
	return this->a;
}

A& B::getA()
{
	return this->a;
}
