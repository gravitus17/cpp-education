#include <iostream>
using namespace std;

int main()
{
    int firstNum;
    int secondNum;
    int sum;
    int correctSum;

    cout << "Введите первое число: ";
    cin >> firstNum;
    cout << "Введите второе число: ";
    cin >> secondNum;
    cout << "Введите из сумму: ";
    cin >> sum;

    correctSum = firstNum + secondNum;
    cout << "-----Проверяем-----\n";
    if (correctSum == sum)
    {
        cout << "Верно!" << endl;
    }
    else
    {
        cout << "Ошибка! Верный результат: " << correctSum << endl;
    }


}