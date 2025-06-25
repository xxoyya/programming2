/*
#include <iostream> 
using namespace std;

class Circle
{
public:
	int x, y;
	int radius;

	Circle() : x{ 0 }, y{ 0 }, radius{ 0 } { }
	Circle(int x, int y, int r) : x{ x }, y{ y }, radius{ r } { }

	void print() {
		cout << "반지름: " << radius << " @(" << x << ", " << y << ")" << endl;
	}
};

int main(void)
{
	Circle objArray[10];

	for (Circle& c : objArray) {
		c.x = rand() % 500;
		c.y = rand() % 300;
		c.radius = rand() % 100;
	}
	for (Circle c : objArray)
		c.print();

	return 0;
}
*/

/*
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price;
public:
	Book(string name, int price) : title{ name }, price{ price } { }
	void print() {
		cout << "제목:" << title << ", 가격:" << price << endl;
	}
};

int main(void) {
	Book books[2] = {
		Book("어서와 C++", 25000),
		Book("어서와 C", 22000)
	};

	cout << "소장하고 있는 책 정보" << endl;
	cout << "======================" << endl;
	for (Book& b : books)
		b.print();
	cout << "======================" << endl;
	return 0;
}
*/

/*
#include <Windows.h>
#include <conio.h>
#include <iostream> 
using namespace std;

class Circle {
public:
	int x, y;
	int radius;

	Circle() : x{ 0 }, y{ 0 }, radius{ 0 } { }
	Circle(int x, int y, int r) : x{ x }, y{ y }, radius{ r } { }

	void draw() {
		int r = radius / 2;
		HDC hdc = GetWindowDC(GetForegroundWindow());
		Ellipse(hdc, x - r, y - r, x + r, y + r);
	}
};

int main(void) {
	Circle objArray[10];

	while (true) {

		char ch = _getch();
		if (ch == 'q') {
			break;
		}
		else if (ch == 'm') {
			system("cls");
			Sleep(100);
			for (Circle& c : objArray) {
				c.x += 100;
				c.draw();
			}
		}
		else {
			for (Circle& c : objArray) {
				c.x = rand() % 500;
				c.y = rand() % 300;
				c.radius = rand() % 100;
				c.draw();
			}
		}
	}
	return 0;
}
*/

/*
#include <vector>
#include <iostream> 
using namespace std;

int main(void) {
	vector<int> fibonacci{ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

	for (auto& number : fibonacci)
		cout << number << ' ';

	cout << endl;
	return 0;
}
*/

#include <vector>
#include <iostream>
using namespace std;

int main(void) {
	vector<int> v1;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	cout << "v1 =";
	for (auto& e : v1) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}