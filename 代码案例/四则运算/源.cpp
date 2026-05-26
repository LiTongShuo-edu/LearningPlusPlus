#include<iostream>
using namespace std;
int main()
{
	//数值区
	double x = 0;
	double y = 0;
	double z = 0;
	double n = 0;
	double m = 0;

	//显示区
	cout << "欢迎使用加法计算器\n支持x+y+z+n+m五数相加求和 " << endl;
	
	//输入区
	cout << "请键入x值:  " << endl;
	cin >> x;

	cout << "请键入y值:  " << endl;
	cin >> y;

	cout << "请键入z值:  " << endl;
	cin >> z;

	cout << "请键入n值:  " << endl;
	cin >> n;

	cout << "请键入m值:  " << endl;
	cin >> m;

	//结果区
	cout << "结果:x+y+z+n+m=   "<<x+y+z+n+m<< endl;

	return 0;
}