#include <iostream>
using namespace std;

int main()
{
    int lengthRow;
    int exclamPoint;
    bool run = true;
    do 
    {
        cout << "Введите общую длину в колонтитуле: ";
        cin >> lengthRow;

        cout << "Введите количество восклицательных знаков: ";
        cin >> exclamPoint;

        if (lengthRow < 3 || exclamPoint < 1)
        {
            cout << "Вы ввели неправильные значения.\n";
            continue;
        }
        else if ( lengthRow - exclamPoint == 1)
        {
            cout << "Не получиться поместить восклицательные знаки в центре колонтитула !\n";
            continue;
        }
        run = false;
    }while(run);

    for (int  col = 0; col < lengthRow; col++)
    {
        if(col < (lengthRow- exclamPoint)/2 || col >= ((lengthRow- exclamPoint)/2 + exclamPoint))
        {
            cout << "~";
        }
        else
        {
            cout << "!";
        }
    }
}