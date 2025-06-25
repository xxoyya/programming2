// 반복을 이용한 게임 프로그램 
#include <iostream>
// 현재 시간을 가져와서 난수 생성에 사용 
#include <time.h> 
using namespace std;

int main()
{
	// 난수 생성 초기화 1장 마지막 주사위랑 마찬가지
	srand(time(NULL));

	int answer = rand() % 100; // 정답 / 0부터 99까지의 랜덤한 정수를 정답으로 설정
	int guess;
	int tries = 0; // 사용자의 시도 횟수를 세는 변수

	// 반복 구조
	do
	{
		cout << "정답을 추측하여 보시오: ";
		cin >> guess;
		tries++; // 시도 횟수 1 증가

		if (guess > answer)
			cout << "제시한 정수가 높습니다.\n";
		if (guess < answer)
			cout << "제시한 정수가 낮습니다.\n";
	}
	// 사용자가 정답을 맞출 때까지 반복 ( 정답x -> while문 계속 반복)
	while (guess != answer);

	cout << "축하합니다. 시도 횟수=" << tries << endl;

	return 0;
}