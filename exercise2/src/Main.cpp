#include <iostream>
#include<string.h>
using namespace std;

/**

---------------------------------------------------------------------------------------------------------------------------------
<<Допълнителна работа>>
---------------------------------------------------------------------------------------------------------------------------------

1. Промяна на кода:

	- PersonalInformation(int age) да е от тип (unsigned int)
	- Account(unsigned long long balance) да е от тип (long long)
	- Account(PersonalInformation* personalInformation) да е от тип (PersonalInformation)

	* Променете по подходящ начин кода, за да работят тези промени

2. Добавки в кода:

	Направете следните функции в клас Account:
		
		- withdraw(long long) - теглене на положителна сума без ограничение
		- safeWithdraw(long long) - теглене на положителна сума само ако съотвеният Account има толкова налични
		- transfer(Account&,long long) - трансфериране на положителна сума от текущия акаунт в друг
		- safeTransfer - същото като transfer, но гледаме дали акаунтът има достатъчно пари
		- deposit(long long) - депозиране на положителна сума пари
		- inDebt() - дали съответният Account е в заем (има отрицателен баланс)

	Направете клас Address:
		полета:
			
			- държава ( char* )
			- град ( char* )
			- yлица ( char* )
		
		функционалност:
			
			- constructors(default/със стойности)
			- destructor
			- setters/getters
			- print
			- equals - дали адресът съвпада с друг адрес

	* Направете променлива (Address address) в клас (PersonalInformation) и добавете съответните промени в него,
	  за да работи. Направете функция която проверява дали един Account има същият адрес като друг Account
			


**/

class PersonalInformation {

	char* name = nullptr;
	int age;

public:

	PersonalInformation() : PersonalInformation("unknown", 0) {}

	PersonalInformation(const char* name, int age) {
		setAge(age);
		setName(name);
	}

	~PersonalInformation() {
		delete[] name;
	}

	void print() const {
		cout << "Name: " << getName() << endl << "Age: " << getAge() << endl;
	}


	void setName(const char* name) {
		delete[] this->name;

		int len = strlen(name) + 1;
		
		this->name = new char[len];
		strcpy_s(this->name, len, name);


	}

	void setAge(int age) {
		this->age = age;
	}

	int getAge() const {
		return this->age;
	}

	const char* getName() const {
		return this->name;
	}

};

class Account {
	

	PersonalInformation* personalInformation = nullptr;
	unsigned long long balance;

public:

	Account() : Account("unknown",0,0){}

	Account(const char* name, int age, unsigned long long balance) {

		setPersonalInformation(name, age);
		setBalance(balance);

	}

	Account(const PersonalInformation& pi, unsigned long long balance) : Account(pi.getName(), pi.getAge(), balance) {}

	~Account() {
		delete personalInformation;
	}

	void print() const {
		getPersonalInformation().print();
		cout << "Balance: " << getBalance() << endl;
	}



	void setPersonalInformation(const PersonalInformation& personalInformation) {
		setPersonalInformation(personalInformation.getName(), personalInformation.getAge());
	}

	void setPersonalInformation(const char* name, int age) {

		delete this->personalInformation;
		this->personalInformation = new PersonalInformation(name, age);

	}

	void setBalance(unsigned long long balance) {
		this->balance = balance;
	}

	const PersonalInformation& getPersonalInformation() const {
		return *personalInformation;
	}


	unsigned long long getBalance() const {
		return balance;
	}

};


int main() {

	/*
	Simple debug here
	*/


	system("pause");

}
