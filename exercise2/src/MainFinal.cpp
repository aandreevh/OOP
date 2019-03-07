#include <iostream>
#include<string.h>
using namespace std;


bool areCharsEqual(const char* a, const char* b) {
	return strcmp(a, b) == 0;
}

class Address {

	char *country = nullptr, *city = nullptr, *street = nullptr;

public:

	Address() : Address("", "", "") {}

	Address(const char* country, const char* city, const char* street) {
		setCountry(country);
		setCity(city);
		setStreet(street);
	}

	~Address() {
		delete[] country, city, street;
	}

	bool equals(const Address& o) const {
		return 
			areCharsEqual(getCountry(), o.getCountry()) 
			&& areCharsEqual(getCity(), o.getCity()) 
			&& areCharsEqual(getStreet(), o.getStreet());
	}

	void print() const {
		cout << "Country: " << getCountry() << endl << "City: " << getCity() << endl << "Street: " << getStreet() << endl;
	}

	///Прекалено много еднотипен код ?
	void setCountry(const char* country) {
		delete[] this->country;

		int len = strlen(country) + 1;

		this->country = new char[len];
		strcpy_s(this->country, len, country);
	}

	void setCity(const char* city) {
		delete[] this->city;

		int len = strlen(city) + 1;

		this->city = new char[len];
		strcpy_s(this->city, len, city);
	}

	void setStreet(const char* street) {
		delete[] this->street;

		int len = strlen(street) + 1;

		this->street = new char[len];
		strcpy_s(this->street, len, street);
	}
	///

	const char* getCountry() const {
		return this->country;
	}

	const char* getCity() const {
		return this->city;
	}

	const char* getStreet() const {
		return this->street;
	}

};

class PersonalInformation {

	Address address;

	char* name = nullptr;
	unsigned int age;

public:

	PersonalInformation() : PersonalInformation(Address(),"", 0) {}

	PersonalInformation(const Address& address, const char* name, unsigned int age) {
		setAge(age);
		setName(name);
		setAddress(address);
	}

	~PersonalInformation() {
		delete[] name;
	}

	void print() const {
		
		cout << "Name: " << getName() << endl << "Age: " << getAge() << endl<<endl;
		cout << "Address" << endl << "-------------------"<<endl;
		getAddress().print();
		cout << "-------------------" << endl<<endl;
	}

	void setAddress(const Address& other) {
		this->address.setCountry(other.getCountry());
		this->address.setCity(other.getCity());
		this->address.setStreet(other.getStreet());
	}

	void setName(const char* name) {
		delete[] this->name;

		int len = strlen(name) + 1;
		
		this->name = new char[len];
		strcpy_s(this->name, len, name);
	}

	void setAge(unsigned int age) {
		this->age = age;
	}

	unsigned int getAge() const {
		return this->age;
	}

	const char* getName() const {
		return this->name;
	}

	const Address& getAddress() const {
		return this->address;
	}

};

class Account {
	

	PersonalInformation personalInformation;
	long long balance;

public:

	Account() : Account(PersonalInformation(),0){}

	Account(const Address& address, const char* name, unsigned int age, long long balance) {

		setPersonalInformation(address,name, age);
		setBalance(balance);

	}

	Account(const PersonalInformation& pi, long long balance) : Account(pi.getAddress(),pi.getName(), pi.getAge(), balance) {}

	
	bool fromSameAddress(const Account& other) {
		return getPersonalInformation().getAddress().equals(other.getPersonalInformation().getAddress());
	}

	bool withdraw(long long amount) {
		if (amount < 0){ 
			return false;
		}

		this->setBalance(this->getBalance() - amount);

		return true;
	}

	bool safeWithdraw(long long amount) {
		if (getBalance() < amount) {
			return false;
		}

		return withdraw(amount);
	}

	bool deposit(long long amount) {
		if (amount < 0) {
			return false;
		}

		setBalance(getBalance() + amount);

		return true;
	}

	bool inDebt() {
		return getBalance() < 0;
	}

	bool transfer(Account& other, long long amount) {
		return withdraw(amount) && other.deposit(amount);
	}

	bool safeTransfer(Account& other, long long amount) {
		return safeWithdraw(amount) && other.deposit(amount);
	}


	void print() const {
		getPersonalInformation().print();
		cout << "Balance: " << getBalance() << endl;
	}



	void setPersonalInformation(const PersonalInformation& personalInformation) {
		setPersonalInformation(personalInformation.getAddress(),personalInformation.getName(), personalInformation.getAge());
	}

	void setPersonalInformation(const Address& address,const char* name, unsigned int age) {

		this->personalInformation.setAddress(address);
		this->personalInformation.setName(name);
		this->personalInformation.setAge(age);

	}

	void setBalance(long long balance) {
		this->balance = balance;
	}

	const PersonalInformation& getPersonalInformation() const {
		return this->personalInformation;
	}


	long long getBalance() const {
		return this->balance;
	}

};




int main() {

	Address a("a", "b", "c");

	Address b("c", "b", "a");


	Account aa(a, "Andrey", 20, 100);
	Account bb(PersonalInformation(b, "Yerdna", 2), 0);

	cout << endl << endl;

	cout <<"From same address: "<< aa.fromSameAddress(bb)<<endl;

	cout <<"Safe transfer: "<< aa.safeTransfer(bb, 50)<<endl;
	cout <<"Safe withdraw: "<< aa.safeWithdraw(50) << endl;

	cout <<"Withdraw: "<< bb.withdraw(1000) << endl;

	cout <<"Debt: "<< bb.inDebt() << endl;

	cout << endl << endl;


	aa.print();
	cout << endl<<endl;

	bb.print();

	cout << endl;

	system("pause");

}
