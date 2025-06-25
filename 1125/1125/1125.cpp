#include <iostream>
#include <string>
using namespace std;

// 부모 클래스: Shape
class Shape {
protected:
    string shapeName; // 도형 이름
public:
    // 생성자
    Shape(const string& name) : shapeName(name) {
        cout << "Shape 생성자 : " << shapeName << endl;
    }
};

// 자식 클래스: Circle
class Circle : public Shape {
private:
    double radius; // 반지름
public:
    // Circle 생성자
    Circle(const string& name, double r) : Shape(name), radius(r) {
        cout << "Circle 생성자 : 반지름 = " << radius << endl;
    }

    // 넓이 계산
    double area() const {
        return 3.14 * radius * radius;
    }

    // displayInfo 함수
    void displayInfo() const {
        cout << "도형 : " << shapeName << ", 반지름 : " << radius
            << ", 넓이 : " << area() << endl;
    }
};

// 자식 클래스: Rectangle
class Rectangle : public Shape {
private:
    double width, height; // 너비와 높이
public:
    // Rectangle 생성자
    Rectangle(const string& name, double w, double h) : Shape(name), width(w), height(h) {
        cout << "Rectangle 생성자 : 너비 = " << width << ", 높이 = " << height << endl;
    }

    // 넓이 계산
    double area() const {
        return width * height;
    }

    // displayInfo 함수
    void displayInfo() const {
        cout << "도형 : " << shapeName << ", 너비 : " << width
            << ", 높이 : " << height << ", 넓이 : " << area() << endl;
    }
};

int main() {
    // Circle 객체 생성
    Circle myCircle("원", 5.0);
    myCircle.displayInfo();
    cout << "-------------------" << endl;

    // Rectangle 객체 생성
    Rectangle myRectangle("직사각형", 4.0, 6.0);
    myRectangle.displayInfo();

    return 0;
}