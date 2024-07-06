#include <iostream>
using namespace std;

int main()
{
    int exp;
    int level;

    cout << "Введите число очков опыта: ";
    cin >> exp;
    cout << "-----Считаем-----\n";

    if ( exp < 0)
    {
        cout << "Опыт не может быть отрицательным !\n";
    }
    else if ( exp < 1000)
    {
        level = 1;
        cout << "Ваш уровень: " << level <<endl;
    }
    else if ( exp < 2500)
    {
        level = 2;
        cout << "Ваш уровень: " << level <<endl;

    }
     else if ( exp < 5000)
    {
        level = 3;
        cout << "Ваш уровень: " << level <<endl;
    }
    else
    {
        level =4;
        cout << "Ваш уровень: " << level << "\nЭто максимальный уровень!\n";

    }
    
}