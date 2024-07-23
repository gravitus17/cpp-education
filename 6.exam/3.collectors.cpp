#include <iostream>

using namespace std;

int main()
{
    string name;
    int debt;
    int bankAccount = 0;

    cout << "Введите имя должника: \n";
    cin >> name;

    cout << "Введите сумму долга должника: \n";
    cin >> debt;

    if (debt < 0) 
    {
        cout << "Отрицательного долга быть не может!\n";
        return 0;
    }
    bankAccount = -debt;

    while (debt > 0)
    {
        int cashIn;
        cout << "Уважаемый, " << name << "! ваш долг составляет -" << debt 
            << "руб. Вам необходимо погасить его немедленно!\n" << "Вы должны внести всю сумму долга прямо сейчас\n";
        cout << "Внесите сумму на свой счет: ";
        cin >> cashIn;
        if (cashIn < 0)
        {
            cout << "Вы вбили отрицательно число!";
            continue;
        }
        debt -= cashIn;
        bankAccount += cashIn;
        
    }
    cout << "Поздравляем вы погасили долг перед банком, на остаток на вашем счёте составляет " << bankAccount << " рублей.\n";
}