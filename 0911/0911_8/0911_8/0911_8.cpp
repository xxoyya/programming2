// 숫자 맞추기 게임
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));

	int answer = rand() % 100;
	int guess;
	int tries = 0;
	// 반복구조
	do {
		cout << "정답을 추측해 보세용: ";
		cin >> guess;
		if (guess > answer) {
			cout << "제시한 숫자가 커용" << endl;
			tries++;
		}
		else if (guess < answer) {
			cout << "제시한 숫자가 작아용" << endl;
			tries++;
		}
	} while (guess != answer);

	cout << "축하합니당. 시도 횟수 = " << tries << endl;

	return 0;
}