// �ݺ��� �̿��� ���� ���α׷� 
#include <iostream>
// ���� �ð��� �����ͼ� ���� ������ ��� 
#include <time.h> 
using namespace std;

int main()
{
	// ���� ���� �ʱ�ȭ 1�� ������ �ֻ����� ��������
	srand(time(NULL));

	int answer = rand() % 100; // ���� / 0���� 99������ ������ ������ �������� ����
	int guess;
	int tries = 0; // ������� �õ� Ƚ���� ���� ����

	// �ݺ� ����
	do
	{
		cout << "������ �����Ͽ� ���ÿ�: ";
		cin >> guess;
		tries++; // �õ� Ƚ�� 1 ����

		if (guess > answer)
			cout << "������ ������ �����ϴ�.\n";
		if (guess < answer)
			cout << "������ ������ �����ϴ�.\n";
	}
	// ����ڰ� ������ ���� ������ �ݺ� ( ����x -> while�� ��� �ݺ�)
	while (guess != answer);

	cout << "�����մϴ�. �õ� Ƚ��=" << tries << endl;

	return 0;
}