#include<iostream>
using namespace std;
int main()
{
	int a = 1;
	int b = 1;
	int x = 0;

	for (int j = 0; j < 9; j++, a++, x++)
	{
		for ( int i = 0; i < x+1; i++)
		{
			int c = a * b;
			cout << a << "*" << b << "=" << c <<"\t";
			b++;
		}
		b = 1;
		cout << endl;
	}

	return 0;
}