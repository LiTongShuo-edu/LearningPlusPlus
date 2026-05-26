#include<iostream>
using namespace std;
int main()
{
	int i = 100;

	cout << "若一个数个、十、百位的立方相加还等于这个数本身，该数即为水仙花数\n以下为所有水仙花数：" << endl;

	do 
	{
		int a = i / 100;
		int b = i / 10 % 10;
		int c = i % 10;
		if (a*a*a + b*b*b + c*c*c == i)
		{
			cout << i << endl;
		}
		i++;
	}
	while (i < 1000);

	return 0;
}