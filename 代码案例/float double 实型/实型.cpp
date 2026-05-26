#include<iostream>
using namespace std;

int main()
{
	//单精度
	float f1 = 3.14159f;
	cout << "f1=" << f1 << endl;
	

	//双精度
	double d1 = 3.14159;
	cout << "d1=" << d1 << endl;
	

	//统计"f1" "d1"占用内存
	cout << "f1占用=" << sizeof(f1) << endl;
	cout << "d1占用=" << sizeof(d1) << endl;
	

	//科学计数法
	cout << "科学计数法↓" << endl;
	int x = 2e3;
	float y = 2e-3;
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;

	return 0;
}