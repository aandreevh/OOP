#include <iostream>
#include <string.h>

#include "PersonalInformation.h"

using namespace std;



PersonalInformation::PersonalInformation() : PersonalInformation(Address(), "", 0) {}

PersonalInformation::PersonalInformation(const PersonalInformation & personalInformation)
{
	setAddress(personalInformation.getAddress());
	setAge(personalInformation.getAge());
	setName(personalInformation.getName());
}

PersonalInformation::PersonalInformation(const Address& address, const char* name, unsigned int age) {
		setAge(age);
		setName(name);
		setAddress(address);
	}

PersonalInformation::~PersonalInformation() {
		delete[] name;
	}

	void PersonalInformation::print() const {

		cout << "Name: " << getName() << endl << "Age: " << getAge() << endl << endl;
		cout << "Address" << endl << "-------------------" << endl;
		getAddress().print();
		cout << "-------------------" << endl << endl;
	}

	void PersonalInformation::setAddress(const Address& other) {
		this->address.setCountry(other.getCountry());
		this->address.setCity(other.getCity());
		this->address.setStreet(other.getStreet());
	}

	void PersonalInformation::setName(const char* name) {
		delete[] this->name;

		int len = strlen(name) + 1;

		this->name = new char[len];
		strcpy_s(this->name, len, name);


	}

	void PersonalInformation::setAge(unsigned int age) {
		this->age = age;
	}

	unsigned int PersonalInformation::getAge() const {
		return this->age;
	}

	const char* PersonalInformation::getName() const {
		return this->name;
	}

	 Address PersonalInformation::getAddress() const {
		return this->address;
	}

	Address & PersonalInformation::getAddress()
	{
		return this->address;
	}
