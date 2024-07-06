#include <iostream>
using namespace std;

int main()
{
    int num1;
    int num2;

    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;
    cout << "-----Проверяем-----\n";

    if (num1 % num2 == 0)
    {
        cout << "Да, число " << num1 << " делится на число " << num2 << " без остатка !\n";
    }
    else
    {
        cout << "Нет, число " << num1 << " не делится на число " << num2 << " без остатка !\n";
    }
}