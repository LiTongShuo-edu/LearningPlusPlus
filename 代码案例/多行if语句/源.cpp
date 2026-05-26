#include<iostream>
using namespace std;
int main()
{
	char w = 'y';
	int i = 0;
	cout << "该程序能判断您输入的数的奇偶\n请键入您要判断的数：" << endl;
	cin >> i;

	cout << "您输入的数是：" << i << endl;

	while (w != 'n')
	{
		switch (i % 2)
		{
		case 1:
		{
			cout << "该数是奇数" << endl;
		}
		break;
		case 0:
		{
			cout << "该数是偶数" << endl;
		}
		break;
		}
	cout << "是否继续？（y/n）" << endl;
	cin >> w;
	}
		return 0;
}