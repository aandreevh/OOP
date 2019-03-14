#pragma once

class Address {

	char *country = nullptr, *city = nullptr, *street = nullptr;

public:

	Address();
	Address(const Address& address);
	Address(const char* country, const char* city, const char* street);

	~Address();

	bool equals(const Address& o) const;

	void print() const;

	void setCountry(const char* country);

	void setCity(const char* city);

	void setStreet(const char* street);

	const char* getCountry() const;

	const char* getCity() const;
	const char* getStreet() const;
};