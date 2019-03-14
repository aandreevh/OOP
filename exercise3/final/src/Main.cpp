#include<iostream>

#include "Account.h"

using namespace std;

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


	return 0;
}
