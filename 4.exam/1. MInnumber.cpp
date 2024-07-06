#include <iostream>
using namespace std;

int main()
{
    int firstNum;
    int secondNum;

    cout << "Введите первое число: ";
    cin >> firstNum;

    cout << "Введите второе число: ";
    cin >> secondNum;

    cout << "-----Проверяем-----\n";

    if (firstNum > secondNum)
    {
        cout << "Наименьшее число: " << secondNum << endl;
    }
    else if (firstNum == secondNum)
    {
        cout <<"Числа равны!\n";
    }
    else
    {
        cout << "наименьшее число: " << firstNum << endl;
    }
}