#include <iostream>
#include <time.h>
#include <string>
using namespace std;

/*
int main() {
	// 정수 변수 number의 주소를 계산하여 p1에 저장
	int number = 10;
	int* p1 = &number;
	// cout << p1 << endl;
	// cout << *p1 << endl;

	*p1 = 11;
	// cout << number << endl;

	// string 뱐수 str의 주소를 계산하여 p2에 저장
	string str = "Hello~";
	string* p2 = &str;
	cout << p2 << endl;

	// p1, p2가 가리키는 공간에 저장된 값을 출력
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


// delete 적용
int main() {
	string* names = nullptr;// 객체 배열
	string* longest = nullptr;// 긴 이름 
	string* shortest = nullptr;// 짧은 이름 
	int length;// 입력할 이름의 개수

	cout << "얼마나 많은 이름을 입력 하시겠습니까? ";
	cin >> length;

	// 이름 입력 
	names = new string[length];
	for (int i = 0; i < length; ++i)
	{
		cout << "이름 입력 # " << i + 1 << ": ";
		cin >> names[i];
	}
	cout << endl;

	cout << "다음은 이름 목록입니다." << endl;
	for (int i = 0; i < length; ++i)
		cout << "이름 #" << i + 1 << ": " << names[i] << endl;

	// 가장 긴 이름과 가장 짧은 이름 찾기 
	longest = &names[0];
	shortest = &names[0];
	for (int i = 1; i < length; ++i)
	{
		if (names[i].length() > longest->length())
			longest = &names[i];
		if (names[i].length() < shortest->length())
			shortest = &names[i];
	}

	cout << "\n가장 긴 이름: " << *longest << endl;
	cout << "가장 짧은 이름: " << *shortest << endl;

	// 리소스 해제
	delete[] names;
	names = nullptr;

	return 0;
}

/* 스마트포인터
int main() {
	unique_ptr<string[]> names;  // 객체 배열을 위한 스마트 포인터
	string* longest = nullptr;   // 긴 이름을 저장할 포인터
	string* shortest = nullptr;  // 짧은 이름을 저장할 포인터
	int length;  // 입력할 이름의 개수

	cout << "얼마나 많은 이름을 입력 하시겠습니까? ";
	cin >> length;

	// 이름 입력
	names = make_unique<string[]>(length);  // 스마트 포인터로 배열 생성
	for (int i = 0; i < length; ++i)
	{
		cout << "이름 입력 # " << i + 1 << ": ";
		cin >> names[i];
	}
	cout << endl;

	cout << "다음은 이름 목록입니다." << endl;
	for (int i = 0; i < length; ++i)
		cout << "이름 #" << i + 1 << ": " << names[i] << endl;

	// 가장 긴 이름과 가장 짧은 이름 찾기
	longest = &names[0];
	shortest = &names[0];
	for (int i = 1; i < length; ++i)
	{
		if (names[i].length() > longest->length())
			longest = &names[i];
		if (names[i].length() < shortest->length())
			shortest = &names[i];
	}

	cout << "\n가장 긴 이름: " << *longest << endl;
	cout << "가장 짧은 이름: " << *shortest << endl;

	// 스마트 포인터가 자동으로 메모리를 해제하므로 delete가 필요 없습니다.

	return 0;
}*/