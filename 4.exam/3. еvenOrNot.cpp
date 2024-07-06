#include <iostream>
using namespace std;

int main ()
{
    int num;

    cout << "Введите число: " ;
    cin >> num;
    cout << "-----Проверяем-----" << endl;

    if (num % 2 == 0)
    {
        cout << "Число " << num << "— чётное.\n"; 
    } 
    else 
    {
        cout << "число" << num << "— нечётное.\n";
    }
    return 0;
}   