#include <iostream>
#include <string>
using namespace std;

// �θ� Ŭ����: Shape
class Shape {
protected:
    string shapeName; // ���� �̸�
public:
    // ������
    Shape(const string& name) : shapeName(name) {
        cout << "Shape ������ : " << shapeName << endl;
    }
};

// �ڽ� Ŭ����: Circle
class Circle : public Shape {
private:
    double radius; // ������
public:
    // Circle ������
    Circle(const string& name, double r) : Shape(name), radius(r) {
        cout << "Circle ������ : ������ = " << radius << endl;
    }

    // ���� ���
    double area() const {
        return 3.14 * radius * radius;
    }

    // displayInfo �Լ�
    void displayInfo() const {
        cout << "���� : " << shapeName << ", ������ : " << radius
            << ", ���� : " << area() << endl;
    }
};

// �ڽ� Ŭ����: Rectangle
class Rectangle : public Shape {
private:
    double width, height; // �ʺ�� ����
public:
    // Rectangle ������
    Rectangle(const string& name, double w, double h) : Shape(name), width(w), height(h) {
        cout << "Rectangle ������ : �ʺ� = " << width << ", ���� = " << height << endl;
    }

    // ���� ���
    double area() const {
        return width * height;
    }

    // displayInfo �Լ�
    void displayInfo() const {
        cout << "���� : " << shapeName << ", �ʺ� : " << width
            << ", ���� : " << height << ", ���� : " << area() << endl;
    }
};

int main() {
    // Circle ��ü ����
    Circle myCircle("��", 5.0);
    myCircle.displayInfo();
    cout << "-------------------" << endl;

    // Rectangle ��ü ����
    Rectangle myRectangle("���簢��", 4.0, 6.0);
    myRectangle.displayInfo();

    return 0;
}