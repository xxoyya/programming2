#include <iostream>
using namespace std;

int main()
{
	int vowel = 0, consonant = 0;
	char ch;

	cout << "�����ڸ� �Է��ϰ� ��Ʈ��-Z�� ġ����" << endl;
	while (cin >> ch) {
		cout << ch << endl;
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			vowel++;
		}
		else
			consonant++;
	}
	cout << "����: " << vowel << endl;
	cout << "����: " << consonant << endl;
	return 0;
}