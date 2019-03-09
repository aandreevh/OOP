#pragma once


class A {

	char* aString;
	int aInt;

public:

	A();
	A(const A&);
	A(const char*, int);

	~A();

	void print() const;

	void setString(const char*);
	void setInt(int);

	const char* getString() const;
	int getInt() const;
};