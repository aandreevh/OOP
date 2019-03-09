#include<iostream>
#include "B.h"
using namespace std;

int main() {

	B b;
	b.getA().setString("Example");
	b.getA().setInt(15);

	b.print();

	system("pause");

	return 0;
}
