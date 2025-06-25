/*
#define _CRT_SECURE_NO_WARNINGS // ������ �� �������� ���� ����
#include <string.h>
class MyString {
private:
	char* s;
	int size;
public:
	MyString(char* c) {
		size = strlen(c) + 1;
		s = new char[size];
		strcpy(s, c);
	}
	~MyString() {
		delete[] s;
	}
};
int main() {
	MyString str((char*)"abcdefghijk"); // (char*) ����� �� ���� ������
	return 0;
}
*/

#include <iostream>
using namespace std;

class Rectangle {
	int width, height;
public:
	Rectangle(int w, int h);
	int calcArea();
};

Rectangle::Rectangle(int w, int h)
{
	width = w;
	height = h;
}

int Rectangle::calcArea()
{
	return width * height;
}

int main()
{
	Rectangle r{ 3, 4 };

	cout << "�簢�� ����: ";
	cout << r.calcArea() << '\n';

	return 0;
}