#pragma once
#include "PersonalInformation.h"



class Account {


	PersonalInformation personalInformation;
	long long balance;

public:

	Account();

	Account(const Address& address, const char* name, unsigned int age, long long balance);
	Account(const Account& account);
	Account(const PersonalInformation& pi, long long balance);


	bool fromSameAddress(const Account& other);

	bool withdraw(long long amount);

	bool safeWithdraw(long long amount);

	bool deposit(long long amount);

	bool inDebt() const;

	bool transfer(Account& other, long long amount);

	bool safeTransfer(Account& other, long long amount);


	void print() const;



	void setPersonalInformation(const PersonalInformation& personalInformation);

	void setPersonalInformation(const Address& address, const char* name, unsigned int age);

	void setBalance(long long balance);

	PersonalInformation getPersonalInformation() const;
	PersonalInformation& getPersonalInformation();


	long long getBalance() const;

};
