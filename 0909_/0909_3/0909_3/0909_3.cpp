#include <iostream>
using namespace std;

int main()
{
	double f_temp;
	double c_temp;

	cout << "�Է�: ";
	cin >> f_temp;

	c_temp = (5.0 / 9.0) * (f_temp - 32);
	cout << "ȭ���µ�" << f_temp << "���� �����µ�" << c_temp << "�Դϴ�" << endl;
	return 0;
}