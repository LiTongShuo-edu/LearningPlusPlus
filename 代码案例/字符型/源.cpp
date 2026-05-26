#include<iostream>
using namespace std;

int main()
{
	char word_1 = 'a';
	char word_2 = 'b';
	cout << "word_1=" << word_1 << endl;
	cout << "word_2=" << word_2 << endl;
	
	//大小
	cout << "word_1大小=" << sizeof(word_1) << endl;
	cout << "word_2大小=" << sizeof(word_2) << endl;

	//结束
	cout << "Over" << endl;

	//ASCII码
	cout << "word_1的ACSII码=" << (int)word_1 << endl;
	cout << "word_2的ACSII码=" << (int)word_2 << endl;

	system("pause");


}