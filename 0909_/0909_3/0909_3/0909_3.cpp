#include <iostream>
using namespace std;

int main()
{
	double f_temp;
	double c_temp;

	cout << "ÀÔ·Â: ";
	cin >> f_temp;

	c_temp = (5.0 / 9.0) * (f_temp - 32);
	cout << "È­¾¾¿Âµµ" << f_temp << "µµ´Â ¼·¾¾¿Âµµ" << c_temp << "ÀÔ´Ï´Ù" << endl;
	return 0;
}