#pragma once
#include "A.h"


class B {

	A a;

public:

	B();
	B(const B&);

	void print() const;

	void setA(const A&);

	A getA() const;
	A& getA();

};