#include <iostream>
using namespace std;


int main()
{
    int ticketNum;
    cout << "Введите номер вашего билета: ";
    cin >> ticketNum;

    if (ticketNum < 0)
    {
        cout << "Введенное число может быть только положительным !\n";
        return 0;
    }
    int iteration = 0;
    int sum1;
    int sum2;
    while (ticketNum !=0)
    {
        if (iteration <= (to_string(ticketNum).length()) / 2)   
        {
            sum1 +=  ticketNum %10;
            ticketNum /=10;
            ++iteration;
        }   
        else
        {
            sum2 += ticketNum % 10;
            ticketNum /= 10;
            ++iteration;
        }
    }

    if (sum1 == sum2)
    {
        cout << "Вот удача! Это счастливый билет!\n";
    }
    else
    {
        cout << "Увы! Это обычный билет.\n";
    }


}