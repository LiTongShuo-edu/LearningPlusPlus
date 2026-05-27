#include<iostream>
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));
	long long i1 = rand() % 100 + 1;
	long long i2 = 0;
	long long a = 0;

	cout << "这是一个猜数游戏，请输入一个1~100的数" <<endl;

	while (i1-i2)
		{
			cin >> i2;
			if (i1>i2)
			{
				cout << "您输入的数偏小" << endl;
			}
				else if (i1<i2)
			{
				cout << "您输入的数偏大" << endl;
			}
		}


	return 0;
}
