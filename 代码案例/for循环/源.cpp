#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	srand(time(0));
	long long x = rand() % 100 + 1;
	long long y = 0;
	cout << "这是一个猜数字游戏，请输入一个1~100之间的数" << endl;
	cin >> y;

	for (int i = 0; x != y ; i = i + 1 )
	{
		if (x > y)
		{
			cout << "\n您猜测的数过小" << endl;
		}
		else if (x < y)
		{
			cout << "\n您猜测的数过大" << endl;
		}
		if (i == 6)
		{
			cout << "\n您失败了" << endl;
			return 0;
		}
		cin >> y;
	}
	cout << "\n您猜对了" << endl;

	return 0;
}