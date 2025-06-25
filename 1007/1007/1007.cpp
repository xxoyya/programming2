/*
* 
#include <windows.h>
#include <stdio.h>

int main()
{
	HDC hdc = GetWindowDC(GetForegroundWindow());
		Ellipse(hdc, 100, 500, 300, 300); //왼쪽 x y 오른쪽 x y -> (100, 500) (300, 300) 점 찍어서 생긴 가상의 사각형 안에 원 그리는 거임
}
*/

/*
#include <iostream>
#include <string>
using namespace std;

class PrintData {
public:
	void print(int i) { cout << i << endl; }
	void print(double f) { cout << f << endl; }
	void print(string s = "No Data!") { cout << s << endl; } // 인자 x-> 기본값인 "No Data!" 출력,  인자 o -> 그 인자값 출력
};
int main() {
	PrintData obj;

	obj.print(1); // int 메서드 호출
	obj.print(3.14); // double 메서드 호출
	obj.print("C++14 is cool."); // string 메서트 호출
	obj.print(); // 인자 없으므로 기본값 지정되어 있는 string 메서드 호출해서 "No Data!" 출력 
	return 0;
}
*/


/*
#include <iostream>
using namespace std;

class Circle {
public:
	double calcArea();

	int radius; //반지름
	string color; //색상

};

//클래스 외부에서 멤버 함수를 구현 (class 안에서 지정하기 넘 길어서 밖에서 구현)
double Circle::calcArea() {
	return 3.14 * radius * radius;
}

int main()
{
	Circle c;
	c.radius = 10;
	cout << c.calcArea() << endl;
	return 0;
}
*/


