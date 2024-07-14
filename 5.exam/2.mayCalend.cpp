#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int holidayInMay[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 13, 14, 20, 21, 27, 28};
    int inputDay;

    cout << "Введите число дня месяца: ";
    cin >> inputDay;

    if (inputDay < 1 || inputDay > 31)
    {
        cout << "Такого дня в месяце не существует\n";
    }
    else
    {   
        if (find(begin(holidayInMay), end(holidayInMay), inputDay) != end(holidayInMay))
        {
            cout << "Ура! сегодня " << inputDay <<"-е число, сегодня выходной!\n";
        }
        else
        {
            cout << "Иди на работу, сегодня не выходной!\n";
        }
    }
}