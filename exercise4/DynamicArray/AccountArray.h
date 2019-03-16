#pragma once
#include "Account.h"

class AccountArray {

	unsigned int size = 0, capacity = 0;

	Account** accounts = nullptr;

	unsigned int getCapacity() const;

	bool resizeCapacity(unsigned int capacity);
	void incrementCapacity();

	void incrementSize();
	void decrementSize();


public:

	AccountArray();
	AccountArray(const AccountArray& other);


	~AccountArray();

	void addAccount(const Account& account);
	void setAccount(const Account& account, unsigned int index);
	bool removeAccount(unsigned int index);

	const Account& getAccount(unsigned int index) const;

	Account& getAccount(unsigned int index);

	unsigned int getSize() const;

	bool isEmpty() const;
};
