#include<iostream>
using namespace std;

int main() 
{
	int n;
	int i = 1;

	cout << "������ �߿��� ����ϰ� ���� ���� �Է��ϼ���: ";
	cin >> n;
	while (i <= 9) {
		cout << n << "*" << i << "=" << n * i << endl;
		i++;
	}
	return 0;
}