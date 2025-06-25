#include<iostream>
using namespace std;

int main()
{
	int n = 2; //초기값 2단
	int i = 1;

	while (n <= 9) {
		while (i <= 9) {
			cout << n << "*" << i << "=" << n * i << endl;
			n++;
			i++;
		}
		
	}
	return 0;
}