#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	do {
		cout << "���ڿ��� �Է��Ͻÿ�: ";
		getline(cin, str);
		cout << "������� �Է�: " << str << '\n';
	} while (str != "����");
	return 0;
}