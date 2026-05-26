#include<iostream>
using namespace std;
int main()
{
    int i = 0;
    cout << "请输入您的高考分数：\n";
    cin >> i;

    cout << "您的分数为：" << i << "\n\n\n"<<endl;

    if (i >= 600)
    {
        cout << "恭喜您考上了一本\n";
    }

    system("pause");
}