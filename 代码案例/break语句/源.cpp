#include<iostream>
using namespace std;
int main()
{
	cout << "请选择副本：\n1.一号副本\n2.二号副本\n3.三号副本\n请输入" << endl;
	int i = 0;
	cin >> i;

	switch (i)
	{
	case 1 :
	{
		cout << "您选择了一号副本" << endl;
	}break;

	case 2 :
	{
		cout << "您选择了二号副本" << endl;
	}break;

	case 3:
	{
		cout << "您选择了三号副本" << endl;
	}break;

	}

	return 0;
}