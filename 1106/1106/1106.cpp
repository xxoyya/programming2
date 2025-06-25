#include <iostream>
#include <time.h>
#include <string>
using namespace std;

/*
int main() {
	// ���� ���� number�� �ּҸ� ����Ͽ� p1�� ����
	int number = 10;
	int* p1 = &number;
	// cout << p1 << endl;
	// cout << *p1 << endl;

	*p1 = 11;
	// cout << number << endl;

	// string ���� str�� �ּҸ� ����Ͽ� p2�� ����
	string str = "Hello~";
	string* p2 = &str;
	cout << p2 << endl;

	// p1, p2�� ����Ű�� ������ ����� ���� ���
	// cout << *p1 << endl;
	cout << *p2 << ", size:" << (*p2).length() << endl;

	return 0;
}*/

/*
int main() {
	int* ptr;
	srand(time(NULL));
	ptr = new int[10];

	for (int i = 0; i < 10; i++) 
		ptr[i] = rand();
	
	for (int i = 0; i < 10; i++)
		cout << ptr[i] << " ";

	delete[] ptr;
	cout << endl;
	return 0;
}*/


// delete ����
int main() {
	string* names = nullptr;// ��ü �迭
	string* longest = nullptr;// �� �̸� 
	string* shortest = nullptr;// ª�� �̸� 
	int length;// �Է��� �̸��� ����

	cout << "�󸶳� ���� �̸��� �Է� �Ͻðڽ��ϱ�? ";
	cin >> length;

	// �̸� �Է� 
	names = new string[length];
	for (int i = 0; i < length; ++i)
	{
		cout << "�̸� �Է� # " << i + 1 << ": ";
		cin >> names[i];
	}
	cout << endl;

	cout << "������ �̸� ����Դϴ�." << endl;
	for (int i = 0; i < length; ++i)
		cout << "�̸� #" << i + 1 << ": " << names[i] << endl;

	// ���� �� �̸��� ���� ª�� �̸� ã�� 
	longest = &names[0];
	shortest = &names[0];
	for (int i = 1; i < length; ++i)
	{
		if (names[i].length() > longest->length())
			longest = &names[i];
		if (names[i].length() < shortest->length())
			shortest = &names[i];
	}

	cout << "\n���� �� �̸�: " << *longest << endl;
	cout << "���� ª�� �̸�: " << *shortest << endl;

	// ���ҽ� ����
	delete[] names;
	names = nullptr;

	return 0;
}

/* ����Ʈ������
int main() {
	unique_ptr<string[]> names;  // ��ü �迭�� ���� ����Ʈ ������
	string* longest = nullptr;   // �� �̸��� ������ ������
	string* shortest = nullptr;  // ª�� �̸��� ������ ������
	int length;  // �Է��� �̸��� ����

	cout << "�󸶳� ���� �̸��� �Է� �Ͻðڽ��ϱ�? ";
	cin >> length;

	// �̸� �Է�
	names = make_unique<string[]>(length);  // ����Ʈ �����ͷ� �迭 ����
	for (int i = 0; i < length; ++i)
	{
		cout << "�̸� �Է� # " << i + 1 << ": ";
		cin >> names[i];
	}
	cout << endl;

	cout << "������ �̸� ����Դϴ�." << endl;
	for (int i = 0; i < length; ++i)
		cout << "�̸� #" << i + 1 << ": " << names[i] << endl;

	// ���� �� �̸��� ���� ª�� �̸� ã��
	longest = &names[0];
	shortest = &names[0];
	for (int i = 1; i < length; ++i)
	{
		if (names[i].length() > longest->length())
			longest = &names[i];
		if (names[i].length() < shortest->length())
			shortest = &names[i];
	}

	cout << "\n���� �� �̸�: " << *longest << endl;
	cout << "���� ª�� �̸�: " << *shortest << endl;

	// ����Ʈ �����Ͱ� �ڵ����� �޸𸮸� �����ϹǷ� delete�� �ʿ� �����ϴ�.

	return 0;
}*/