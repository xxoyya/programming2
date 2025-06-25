#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
	string number;
	int balance;

public:
	void init(string, int);
	void deposit(int amount);
	void withdraw(int amount);

	int getBalance() const {
		return balance;
	}
};

/* 
���.h:  Ŭ���� �������̽� �ۼ�
Ŭ������.cpp:  Ŭ���� ����
main.cpp:   Ŭ���� ���
*/