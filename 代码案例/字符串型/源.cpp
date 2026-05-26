#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1 = "hello world";

	cout << s1 << endl;
	cout << "hello world，也就是变量s1，占用了 " << sizeof(s1) << "字节空间" << endl;



	system("pause");
}