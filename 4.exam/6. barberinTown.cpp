#include <iostream>
using namespace std;

int main() {
    int mansCount;
    int barbersCount;

    cout << "************** Барбершоп-калькулятор **************\n";
    cout << "Введите число мужчин в городе: ";
    cin >> mansCount;

    cout << "Сколько уже барберов удалось нанять? ";
    cin >> barbersCount;
    if (mansCount < 0|| barbersCount < 0 )
    {
        cout << " Числа не могут быть отрицательными!\n";
    }
    else
    {
        // Сколько человек может постричь один барбер за одну смену?
        int mansPerBarber = 8; // один человек в час, смена 8 часов
        // Сколько человек успеет постричь барбер за месяц?
        int mansPerBarberPerMonth = mansPerBarber * 30;
        cout << "Один барбер стрижет столько клиентов в месяц " << mansPerBarberPerMonth << "\n";

        // Сколько нужно барберов, чтобы постричь mansCount человек?
        int requiredBarbersCount = mansCount / mansPerBarberPerMonth;
        if (mansCount % mansPerBarberPerMonth != 0) {
            requiredBarbersCount += 1;
        }

        cout << "Необходимое число барберов: " << requiredBarbersCount << "\n";

        // Сколько человек успеют посчтричь requiredBarbersCount за месяц?
        cout << requiredBarbersCount << " барбера могут постричь "
        << requiredBarbersCount * mansPerBarberPerMonth << " мужчин за месяц.\n";

        // Сравниваем с количеством имеющихся барберов
        if (requiredBarbersCount > barbersCount) 
        {
            cout << "Нужно больше барберов!!!\n";
        } 
        else if (requiredBarbersCount == barbersCount) 
        {
            cout << "Барберов ровно столько, сколько нужно!!!\n";
        } 
        else if (barbersCount > requiredBarbersCount * 2) 
        {
            cout << "У вас работает в два раза больше барберов, чем это нужно!!!\n";
        }
        else
        {
            cout << "Барберов хватает!!!\n";
        }
    }
    
}
