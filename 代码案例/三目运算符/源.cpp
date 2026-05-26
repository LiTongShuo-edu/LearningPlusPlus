#include<iostream>
using namespace std;
int main()
{
	int A = 0;
	int B = 0;
	int C = 0;

	cout << "数1= " << endl;
	cin >> A;

	cout << "数2= " << endl;
	cin >> B;

	cout << "数1= " <<A<< endl;
	cout << "数2= " <<B<< endl;

	C = A > B ? A : B;

	cout << "最大的数是：" << C << endl;

	return 0;
}