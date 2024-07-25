#include <iostream>
using namespace std;

int main()
{
    int months;
    int buckWheat = 100;
    int run = 1;
    do 
    {
        months = 0;
        while(months <=0)
        {
        cout << "Введите количество месяцев: ";
        cin >> months;

        if (months <= 0)
        {
            cout << "Вы ввели 0 или  отрицательное число!\n";
        }
        }

        buckWheat = 100;

        for (int month = 0 ; month <= months; month++)
        {
            buckWheat -= 4;

            if (buckWheat <= 0)
            {
                cout << "После " << month << " месяца гречка закончится.\n";
                break;
            }

            cout << "После " << month << " месяца у вас останется в запасе " 
                << buckWheat << " кг гречки.\n";
        }

        cout <<  "Хотите продолжить программу ? (1 - да, 2 - нет)\n";
        cin >> run;
    }while (run == 1);
}