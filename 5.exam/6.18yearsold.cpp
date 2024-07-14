#include <iostream>
using namespace std;

int main()
{
    int birthDate[3];
    int todayDate[3];
    cout << "Введите текущую дату:  \n";
    cin >> todayDate[0];

    if ( todayDate[0] > 31)
    {
        cout << "В месяце не может быть больше 31 дня.";
        return 0;
    }

    cout << "/";
    cin >>  todayDate[1];

    if (todayDate[1] < 1 || todayDate[1] > 12)
    {
        cout << "В году не больше 12 месяцев\n";
        return 0;
    }
    else if ( (todayDate[1] == 4 || todayDate[1] == 6 || todayDate[1] == 9 || todayDate[1] ==1) && todayDate[0] >= 31 )
    {
        cout <<"В этом месяцк только 30 дней\n";
        return 0;
    }
  
    cout << "/\n";
    cin >> todayDate[2];

    if (todayDate[2] > 2024)
    {
        cout << "Уходи отсюда, путшественник из будущего, не нарушай пространственно-временной континиум!\n";
        return 0;
    }
    else if (todayDate[1] == 2 && todayDate[0] > 29)
    {
        cout << "Феврале только 28 дней\n";
        return 0;
    }
    else if ( todayDate[0] == 29 && !(todayDate[2] % 4 == 0 && todayDate[2] % 100 != 0 || todayDate[2] % 400 == 0))
    {
        cout << "Год не высокосный, в феврале только 28 дней\n";
        return 0;
    }

    cout << "Введите дату рождения: \n";
    cin >> birthDate[0];

    if ( todayDate[0] > 31)
    {
        cout << "В месяце не может быть больше 31 дня.";
        return 0;
    }


    cin >>  birthDate[1];
    cout << "/";

    if (birthDate[1] < 1 || birthDate[1] > 12)
    {
        cout << "В году не больше 12 месяцев\n";
        return 0;
    }
    else if ( (birthDate[1] == 4 || birthDate[1] == 6 || birthDate[1] == 9 || birthDate[1] ==1) && birthDate[0] >=31 )
    {
        cout <<"В этом месяцк только 30 дней\n";
        return 0;
    }
    cout << "/\n";
    cin >> birthDate[2];

    if (birthDate[2] > 2024)
    {
        cout << "Уходи отсюда, путшественник из будущего, не нарушай пространственно-временной континиум!\n";
        return 0;
    }
    else if (birthDate[1] == 2 && birthDate[0] > 29)
    {
        cout << "Феврале только 28 дней\n";
        return 0;
    }
    else if ( birthDate[0] == 29 && !(birthDate[2] % 4 == 0 && birthDate[2] % 100 != 0 || birthDate[2] % 400 == 0))
    {
        cout << "Год не высокосный, в феврале только 28 дней\n";
        return 0;
    }

    
    if (todayDate[2] - birthDate[2] < 17)
    {
        cout << "Мы не продаем алкоголь несовершеннолетним!\n";
    }
    else if (todayDate[2] - birthDate[2] == 17 && birthDate[1] -todayDate[1] > 0 )
    {
        cout << " Извини малец, приходи через несколько месяцев!\n";
    }
    else if (todayDate[2] - birthDate[2] == 17 && birthDate[1] -todayDate[1] == 0 && birthDate[0] - todayDate[0] <=0 )
    {
        cout << "Парень приходи через несколько дней\n";
    }
    else
    {
        cout << " Добро пожаловать! Вам виски или бренди ?\n";
    }

    return 0;
}