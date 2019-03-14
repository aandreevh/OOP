#pragma once
#include "Address.h"

class PersonalInformation {

	Address address;

	char* name = nullptr;
	unsigned int age;

public:

	PersonalInformation();
	PersonalInformation(const PersonalInformation& personalInformation);
	PersonalInformation(const Address& address, const char* name, unsigned int age);

	~PersonalInformation();

	void print() const;

	void setAddress(const Address& other);

	void setName(const char* name);

	void setAge(unsigned int age);

	unsigned int getAge() const;

	const char* getName() const;

	Address getAddress() const;
	Address& getAddress();

};