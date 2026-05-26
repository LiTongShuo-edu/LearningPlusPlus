#include <iostream>
using namespace std;

int main()
{
    bool b1 = true;
    bool b2 = false;


    cout << b1 << endl;
    cout << b2 << endl;

    cout << "b1占用" << sizeof(b1) << "字节\n";
    cout << "b2占用" << sizeof(b2) << "字节\n";


    system("pause");
}
