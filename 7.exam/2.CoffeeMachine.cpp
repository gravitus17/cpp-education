#include <iostream>
using namespace std;

int main()
{
    
    int water;
    int milk;
    int userChoice;
    int americanoSum = 0;
    int latteSum = 0;
    bool waterRun = true;
    bool  milkRun = true;
    bool choiceRun = true;
    do{
        
        cout << "Введите количество воды в мл: ";
        cin >> water;

        if (water < 0)
        {
            cout << "Вы ввели отрицательное число !\n";
            continue;
        }
        waterRun = false;
    }while(waterRun);

    do{
        cout << "Введите количество молока в мл: ";
        cin >> milk;

        if (milk < 0)
        {
            cout << "Вы ввели отрицательное число !\n";
            continue;
        }
        milkRun = false;
    }while(milkRun);

    
    while(water >= 300 && milk >=270)
    {
        do{
            choiceRun = true;
            cout << "Выберите напиток (1 — американо, 2 — латте): ";
            cin >> userChoice;
            if (userChoice !=1 && userChoice != 2)
            {
                cout << "Вы вбили неправильный номер!\n";
                continue;
            }
            choiceRun = false;
        }while(choiceRun);
        if (userChoice ==1)
        {
            cout << "Ваш напиток готов.\n";
            water -=300;
            americanoSum++;
        }
        else
        {
            cout << "Ваш напиток готов.\n";
            water -= 30;
            milk -= 270;
            latteSum++;
        }
    }
    if (milk <= 270 && water >= 300 )
    {
        cout << "В кофемашине закончилось молоко.\n";
        while( water >= 300)
        {
            do{
                choiceRun = true;
                cout << "Выберите напиток (1 — американо)\n";
                cin >> userChoice;
                if (userChoice != 1)
                {
                    cout << "Вы вбили неправильный номер!\n";
                    continue;
                }
                choiceRun = false;
            }while(choiceRun);
            cout << "Ваш напиток готов.\n";
            water -= 300;
            americanoSum++;
        }
    }
    else if (milk >= 270 && water >=30)
    {
        cout << "Недостаточно воды для Американо.\n";
        while (milk >= 270 && water >=30)
        {
            do{
                choiceRun = true;
                cout << "Выберите напиток (2 — латте)\n";
                cin >> userChoice;
                if (userChoice != 2)
                {
                    cout << "Вы вбили неправильный номер!\n";
                    continue;
                }
                choiceRun = false;
            }while(choiceRun);
            cout << "Ваш напиток готов.\n";
            water -= 30;
            milk -= 270;
            ++latteSum;
        }        
    }
    cout << "В кофемашине закончились ингредиенты.\n";
    cout << "***Отсчёт***\n";
    cout << "Ингредиентов осталось:\n               Вода: " << water 
        << " мл\n               Молоко: " << milk << " мл\n";
    cout << "Кружок американо приготовлено: " << americanoSum << endl;
    cout << "Кружок латте приготовлено: " << latteSum << endl;
}