#include "bank.h"

int main() {
	BankAccount obj;

	obj.init("1111", 1000000); // °èÁÂ¹øÈ£, ÀÜ¾×
	cout << "ÇöÀç ÀÜ¾×: " << obj.getBalance() << endl;
	obj.deposit(1000000);
	cout << "after deposit(1000000) ÇöÀç ÀÜ¾×: " << obj.getBalance() << endl;
	obj.withdraw(1000000);
	cout << "after withdraw(1000000) ÇöÀç ÀÜ¾×: " << obj.getBalance() << endl;

	return 0;
}