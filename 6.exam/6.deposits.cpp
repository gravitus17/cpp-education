#include <iostream>
using namespace std;

int main()
{
    int deposit;
    int percent;
    int desireSum;

    cout << "Введите размер вклада: ";
    cin >> deposit;
    cout << "Введите процент ставки: ";
    cin >> percent;
    cout << "Введите желаемую сумму: ";
    cin >> desireSum;

    int year = 0;

    while (deposit < desireSum)
    {
        int percentInvest = (deposit * percent)/100;
        deposit += percentInvest;
        year++;

    }
    cout << "Придется подождать: " << year <<" лет\n";
}