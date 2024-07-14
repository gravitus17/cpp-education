#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int firstDayOfMonth;
    vector <int> holidayInMay = {1, 2, 3, 4, 5, 8, 9, 10};
    vector <int> weekendInMay;
    int inputDay;

    cout << "Введите номер дня недели начала месяца: ";
    std::cin >> firstDayOfMonth;

    if (firstDayOfMonth <1 && firstDayOfMonth >7) // проверяем число дня неделя ползователя
    {
        cout << "В неделе 7 дней\n";
    }
    else if ( firstDayOfMonth == 6 || firstDayOfMonth ==7) // если начало недели пришлось на выходной
    { 
        if ( firstDayOfMonth == 6)
        {
            weekendInMay.push_back(firstDayOfMonth+2); 
            weekendInMay.push_back(weekendInMay.back()+1);
                //если воскресенье, то высчитываем отдельно воскресенье и добавляем в конец списка
        } 
        else
        {
            weekendInMay.push_back(firstDayOfMonth++);
        }
    }
    else
    {
        int firstWeelend = 7 - firstDayOfMonth;
        weekendInMay.push_back((firstWeelend));
        weekendInMay.push_back(weekendInMay.back()+1);   
    }
    for (int i = weekendInMay.back(); i <=31; i = weekendInMay.back() + 6)
            if (find(begin(weekendInMay), end(weekendInMay), i) != end(weekendInMay))
            {
                continue;
            }
            else
            {
                weekendInMay.push_back(i);
                if (weekendInMay.back() == 31)
                {
                    break;
                }
                else
                {
                    weekendInMay.push_back(i+1);
                }
            }
    cout << "Введите число дня месяца: ";
    std::cin >> inputDay;

    if (inputDay < 1 || inputDay > 31)
    {
        cout << "Такого дня в месяце не существует\n";
    }
    else
    {   


        if (find(begin(holidayInMay), end(holidayInMay), inputDay) != end(holidayInMay)||
        find(begin(weekendInMay), end(weekendInMay), inputDay) != end(weekendInMay))
        {
            cout << "Ура! сегодня " << inputDay <<"-е число, сегодня выходной!\n";
        }
        else
        {
            cout << "Иди на работу, сегодня не выходной!\n";
        }
    }

    return 0;
}