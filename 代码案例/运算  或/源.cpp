#include <iostream>
using namespace std;
int main()
{
	short a = 1;
	short b = 1;
	cout << (a || b) << endl;

	a = 0;
	b = 1;
	cout << (a || b) << endl;

	a = 0;
	b = 0;
	cout << (a || b) << endl;

	return 0;
}