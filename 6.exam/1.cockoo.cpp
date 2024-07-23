#include <iostream>
using namespace std;

int main()
{
    int hour;
    cout << "Введите который часа !\n";
    cin >> hour;

    if (hour < 1 || hour > 24)
    {
        cout << "В сутках двадцать четыре часа\n";
        return 0;
    }
    int count = 0;

    while( hour != count )
    {
        cout << "Ку-ку !\n";
        ++count;
    }
    

}