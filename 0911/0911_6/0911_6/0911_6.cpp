/*
#include <iostream>
using namespace std;

int main()
{
	for (int i = 1; i < 10; i++)
	{
		cout << i << " ";
		if (i == 4)
			break;
	}
	return 0;
}
*/


#include <iostream>
using namespace std;

int main()
{
	int i = 0;
	do {
		i++;
		cout << "continue 문장 전에 있는 문장" << endl;
		continue;
		cout << "continue 문장 후에 있는 문장" << endl;
	} while (i < 3);
	return 0;
}