#include "bank.h"

int main() {
	BankAccount obj;

	obj.init("1111", 1000000); // ���¹�ȣ, �ܾ�
	cout << "���� �ܾ�: " << obj.getBalance() << endl;
	obj.deposit(1000000);
	cout << "after deposit(1000000) ���� �ܾ�: " << obj.getBalance() << endl;
	obj.withdraw(1000000);
	cout << "after withdraw(1000000) ���� �ܾ�: " << obj.getBalance() << endl;

	return 0;
}