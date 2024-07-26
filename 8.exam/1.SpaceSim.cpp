#include <iostream>
#include <cmath>
#include <limits>
#include <numeric>
using namespace std;


float controlInput()
{
    while(true)
    {
        float value;  // попробуйте разные типы данных
        std::cin >> value;
    
        if (std::cin.fail() || std::cin.peek() != '\n'|| value <= 0)
        {
            std::cerr << "Ошибка ввода данных\n";
        
            // Данные две строки необходимы для очистки буфера ввода, без них, при последующем вводе данных, произойдёт зацикливание:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
            // Если нужно прервать программу:
            // return 1; // выход из функции main, соответственно и из программы
            // exit(1); // а так можно выйти из программы в любом месте
            // цифры - это номера ошибок передаваемые программой в ОС,
            // 0 - всё хорошо, не 0 - какой-то код, который разработчик устанавливает сам...
        }
        else
        {
            std::cout << value << '\n';
            return value;
            exit(1);
        }
    }
    return 0;
}

int main()
{
    //float tractionForce;


    cout << "Введите силу тяги: ";
    float tractionForce = controlInput();

    cout << "Введите массу корабля: ";
    float weight = controlInput();
    
    cout << "Введите время в секундах: ";
    float timeSec = controlInput();

    float spaceshipDistance = ((tractionForce/weight) * pow(timeSec, 2))/2;

    cout << "Ваш корабль окажеться на расстоянии " << spaceshipDistance << " от начальной точки.\n";


}