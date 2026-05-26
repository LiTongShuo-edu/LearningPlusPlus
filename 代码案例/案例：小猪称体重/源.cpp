#include<iostream>
using namespace std;
int main()
{
	cout << "有三只小猪 x y z，请你输入它们的体重" << endl;
	long long x = 0;
	long long y = 0;
	long long z = 0;
	cout << "\n请输入x的体重" << endl;
	cin >> x;

	cout << "\n请输入y的体重" << endl;
	cin >> y;

	cout << "\n请输入z的体重" << endl;
	cin >> z;

	cout << "小猪x体重为" << x << endl;
	cout << "小猪y体重为" << y << endl;
	cout << "小猪z体重为" << z << endl;

	if (x > y)
	{
		if (x > z)
		{
			cout << "\n\nx最重\n";
		}
		else
		{
			cout << "\n\nz最重\n";
		}
	}
	else 
	{
		if (y > z)
		{
			cout << "\n\ny最重\n";
		}
		else
		{
			cout << "\n\nz最重\n";
		}
	}
	

	return 0;
}