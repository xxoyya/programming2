/*
* 
#include <windows.h>
#include <stdio.h>

int main()
{
	HDC hdc = GetWindowDC(GetForegroundWindow());
		Ellipse(hdc, 100, 500, 300, 300); //���� x y ������ x y -> (100, 500) (300, 300) �� �� ���� ������ �簢�� �ȿ� �� �׸��� ����
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
	void print(string s = "No Data!") { cout << s << endl; } // ���� x-> �⺻���� "No Data!" ���,  ���� o -> �� ���ڰ� ���
};
int main() {
	PrintData obj;

	obj.print(1); // int �޼��� ȣ��
	obj.print(3.14); // double �޼��� ȣ��
	obj.print("C++14 is cool."); // string �޼�Ʈ ȣ��
	obj.print(); // ���� �����Ƿ� �⺻�� �����Ǿ� �ִ� string �޼��� ȣ���ؼ� "No Data!" ��� 
	return 0;
}
*/


/*
#include <iostream>
using namespace std;

class Circle {
public:
	double calcArea();

	int radius; //������
	string color; //����

};

//Ŭ���� �ܺο��� ��� �Լ��� ���� (class �ȿ��� �����ϱ� �� �� �ۿ��� ����)
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


