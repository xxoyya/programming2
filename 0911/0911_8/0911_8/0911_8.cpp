// ���� ���߱� ����
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));

	int answer = rand() % 100;
	int guess;
	int tries = 0;
	// �ݺ�����
	do {
		cout << "������ ������ ������: ";
		cin >> guess;
		if (guess > answer) {
			cout << "������ ���ڰ� Ŀ��" << endl;
			tries++;
		}
		else if (guess < answer) {
			cout << "������ ���ڰ� �۾ƿ�" << endl;
			tries++;
		}
	} while (guess != answer);

	cout << "�����մϴ�. �õ� Ƚ�� = " << tries << endl;

	return 0;
}