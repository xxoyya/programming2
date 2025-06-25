/*
#define _CRT_SECURE_NO_WARNINGS // 마지막 줄 오류나서 적는 문장
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
	MyString str((char*)"abcdefghijk"); // (char*) 써야함 안 쓰면 오류남
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

	cout << "사각형 넓이: ";
	cout << r.calcArea() << '\n';

	return 0;
}