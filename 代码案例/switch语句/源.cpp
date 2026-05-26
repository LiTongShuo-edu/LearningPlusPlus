#include<iostream>
using namespace std;
int main()
{
	cout << "评分（0~10分） :  " << endl;
	int a = 0;
	cin >> a;
	cout << "您的评分是：" << a << endl;

	switch (a)
	{
		case 10:
			cout << "您认为这是一部经典电影\n";
		break;

	    case 9:
			cout << "您认为这是一部经典电影\n";
		break;

		case 8:
			cout << "您认为这部电影是经典电影\n";
		break;

		case 7:
			cout << "您认为这部电影是经典电影\n";
		break;

		case 6:
			cout << "您认为这部电影一般\n";
		break;

		case 5:
			cout << "您认为这部电影一般\n";
		break;
		
		default:
			cout << "您认为这部电影是烂片\n";
		break;

	}

	return 0;
}