#include<iostream>
using namespace std;
int main()
{
	//=
	long long a = 10;
	a = 100;//赋值：直接改变变量数值
	cout << "a= " << a << endl;

	//+=
	a = 10;
	a += 5;
	cout << "a= " << a << endl;

	//-=
	a = 10;
	a -= 5;
	cout << "a= " << a << endl;

	//*=
	a = 10;
	a *= 5;
	cout << "a= " << a << endl;

	//%=
	a = 10;
	a %= 3;
	cout << "a= " << a << endl;


	return 0;
}