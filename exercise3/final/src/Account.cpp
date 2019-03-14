#include "Account.h"
#include <iostream>

using namespace std;



	Account::Account() : Account(PersonalInformation(), 0) {}

	Account::Account(const Address& address, const char* name, unsigned int age, long long balance) {

		setPersonalInformation(address, name, age);
		setBalance(balance);

	}

	Account::Account(const Account & account)
	{
		setPersonalInformation(account.getPersonalInformation());
		setBalance(account.getBalance());
	}

	Account::Account(const PersonalInformation& pi, long long balance) : Account(pi.getAddress(), pi.getName(), pi.getAge(), balance) {}


	bool Account::fromSameAddress(const Account& other) {
		return getPersonalInformation().getAddress().equals(other.getPersonalInformation().getAddress());
	}

	bool Account::withdraw(long long amount) {
		if (amount < 0) {
			return false;
		}

		this->setBalance(this->getBalance() - amount);

		return true;
	}

	bool Account::safeWithdraw(long long amount) {
		if (getBalance() < amount) {
			return false;
		}

		return withdraw(amount);
	}

	bool Account::deposit(long long amount) {
		if (amount < 0) {
			return false;
		}

		setBalance(getBalance() + amount);

		return true;
	}

	bool Account::inDebt() const {
		return getBalance() < 0;
	}

	bool Account::transfer(Account& other, long long amount) {
		return withdraw(amount) && other.deposit(amount);
	}

	bool Account::safeTransfer(Account& other, long long amount) {
		return safeWithdraw(amount) && other.deposit(amount);
	}


	void Account::print() const {
		getPersonalInformation().print();
		cout << "Balance: " << getBalance() << endl;
	}



	void Account::setPersonalInformation(const PersonalInformation& personalInformation) {
		setPersonalInformation(personalInformation.getAddress(), personalInformation.getName(), personalInformation.getAge());
	}

	void Account::setPersonalInformation(const Address& address, const char* name, unsigned int age) {

		this->personalInformation.setAddress(address);
		this->personalInformation.setName(name);
		this->personalInformation.setAge(age);

	}

	void Account::setBalance(long long balance) {
		this->balance = balance;
	}

	PersonalInformation Account::getPersonalInformation() const {
		return this->personalInformation;
	}

	PersonalInformation& Account::getPersonalInformation()
	{
		return this->personalInformation;
	}


	long long Account::getBalance() const {
		return this->balance;
	}