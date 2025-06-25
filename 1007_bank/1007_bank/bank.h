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
헤더.h:  클래스 인터페이스 작성
클래스명.cpp:  클래스 정의
main.cpp:   클래스 사용
*/