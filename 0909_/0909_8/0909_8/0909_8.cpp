#include <iostream>
using namespace std;

int main()
{
	int a, b, c, largest;

	cout << "3���� ������ �Է��Ͻÿ�:";
	cin >> a >> b >> c;

	if (a > b && a > c)
		largest = a;
	else if (b > a && b > c)
		largest = b;
	else
		largest = c;
	
	cout << "���� ū ������ " << largest << endl;
	return 0;
}