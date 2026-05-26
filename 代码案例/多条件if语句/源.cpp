#include<iostream>
using namespace std;

int main()
{
	int i = 0;
	cout << "请输入您的分数：" << endl;
	cin >> i;
	cout << "\n\n您的分数是：" << i << endl;

	if (i >= 6666)
	{
		cout << "恭喜您考上了 人类感谢你 大学" << endl;
	}
	else if (i >= 600)
	{
		cout << "\n\n恭喜，您考上了一本大学" << endl;
	}
	else if (i >= 500)
	{
		cout << "\n\n您考上了二本大学" << endl;
	}
	else if (i >= 400)
	{
		cout << "您考上了三本大学" << endl;
	}
	else
	{
		cout << "恭喜您考上了家里蹲大学" << endl;
	}

	return 0;
}