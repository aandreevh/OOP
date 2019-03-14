#include "Address.h"
#include <string.h>
#include <iostream>

using namespace std;

 bool areCharsEqual(const char* a, const char* b) {
	return strcmp(a, b) == 0;
}

Address::Address() : Address("", "", "") {}

Address::Address(const Address & address)
{
	setCity(address.getCity());
	setCountry(address.getCountry());
	setStreet(address.getStreet());
}

Address::Address(const char* country, const char* city, const char* street) {
		setCountry(country);
		setCity(city);
		setStreet(street);
	}

	Address::~Address() {
		delete[] country, city, street;
	}

	bool Address::equals(const Address& o) const {
		return
			areCharsEqual(getCountry(), o.getCountry())
			&& areCharsEqual(getCity(), o.getCity())
			&& areCharsEqual(getStreet(), o.getStreet());
	}

	void Address::print() const {
		cout << "Country: " << getCountry() << endl << "City: " << getCity() << endl << "Street: " << getStreet() << endl;
	}

	void Address::setCountry(const char* country) {
		delete[] this->country;

		int len = strlen(country) + 1;

		this->country = new char[len];
		strcpy_s(this->country, len, country);
	}

	void Address::setCity(const char* city) {
		delete[] this->city;

		int len = strlen(city) + 1;

		this->city = new char[len];
		strcpy_s(this->city, len, city);
	}

	void Address::setStreet(const char* street) {
		delete[] this->street;

		int len = strlen(street) + 1;

		this->street = new char[len];
		strcpy_s(this->street, len, street);
	}

	const char* Address::getCountry() const {
		return this->country;
	}

	const char* Address::getCity() const {
		return this->city;
	}

	const char* Address::getStreet() const {
		return this->street;
	}
