#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	srand(time(NULL));
	int dice1 = (rand() % 6) + 1;
	int dice2 = (rand() % 6) + 1;

	cout << " �ֻ���1: " << dice1 << ", �ֻ���2" << dice2;
	cout << ", �� �ֻ��� �� = " << dice1 + dice2 << endl;
	return 0;
}