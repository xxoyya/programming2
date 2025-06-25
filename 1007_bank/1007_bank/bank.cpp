#include "bank.h"

void BankAccount::init(string n, int bal)
{
	number = n;
	balance = bal;
}

void BankAccount::deposit(int amount)
{
	balance += amount;
}

void BankAccount::withdraw(int amount)
{
	if (balance >= amount) {
		balance -= amount;
	}
}