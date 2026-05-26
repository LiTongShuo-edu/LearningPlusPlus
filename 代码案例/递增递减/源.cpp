#include<iostream>
using namespace std;
int main()
{
	//前置递增和后置递增都是让变量+1
	int a = 1;
	++a;
	cout << "a= " << a << endl;

	int b = 1;
	b++;
	cout << "b= " << b << endl;

	//前置递增先进行+1
	//后置递增后进行+1
	
	//前置递增
	int a2 = 10;
	int b2 = ++a2 * 2;
	cout << b2 << endl;

	//后置递增
	int a3 = 10;
	int b3 = a3++ * 4;
	cout << a3 << endl;
	cout << b3 << endl;

	return 0;
}