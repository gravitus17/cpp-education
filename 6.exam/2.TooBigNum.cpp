#include <iostream>
using namespace std;

int main()
{
    int inputNum;
    cout << "Введите число:";
    cin >> inputNum;

    int count = 0;
    if (inputNum == 0)
        ++count;

    while (inputNum !=0)
    {
        inputNum /=10;
        ++count;
    }

    cout << "Введённом числе " << count << " знаков.\n";
}