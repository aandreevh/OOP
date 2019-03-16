#include "AccountArray.h"


	bool AccountArray::resizeCapacity(unsigned int capacity) {
		if (getCapacity() >= capacity) {
			return false;
		}

		this->capacity = capacity;

		Account** newArray = new Account*[getCapacity()];

		for (unsigned int i = 0; i < getSize(); i++) {
			newArray[i] = accounts[i];
		}

		delete[] accounts;

		accounts = newArray;

		return true;
	}

	void AccountArray::incrementSize() {

		if (getSize() == getCapacity()) {
			incrementCapacity();
		}


		this->size++;
	}

	void AccountArray::decrementSize() {
		if (getSize() > 0) this->size--;
	}

	void AccountArray::incrementCapacity() {
		if (getCapacity() == 0) {
			resizeCapacity(1);
		}
		else {
			resizeCapacity(2 * getCapacity());
		}
	}



	AccountArray::~AccountArray() {

		for (unsigned int i = 0; i < getSize(); i++)
			delete accounts[i];

		delete[] accounts;
	}

	void AccountArray::addAccount(const Account& account) {
		incrementSize();

		accounts[getSize() - 1] = new Account(account.getPersonalInformation(), account.getBalance());
	}

	bool AccountArray::removeAccount(unsigned int index) {
		if (index >= getSize()) return false;

		delete accounts[index];

		decrementSize();

		for (unsigned int i = index; i < getSize(); i++) {
			accounts[i] = accounts[i + 1];
		}

		

		return true;
	}

	const Account& AccountArray::getAccount(unsigned int index) const {
		if (index < getSize()) {
			return *accounts[index];
		}
		//Грешка ?
	}

	Account& AccountArray::getAccount(unsigned int index) {
		if (index < getSize()) {
			return *accounts[index];
		}
		//Грешка ?
	}

	unsigned int AccountArray::getSize() const {
		return this->size;
	}

	bool AccountArray::isEmpty() const
	{
		return (getSize()==0);
	}