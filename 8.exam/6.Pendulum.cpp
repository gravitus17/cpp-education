#include <iostream>
#include <numeric>
#include <limits>

using namespace std;

float controlInput()
{
    while(true)
    {
        float value; 
        std::cin >> value;
    
        if (std::cin.fail() || std::cin.peek() != '\n'|| value < 0)
        {
            std::cerr << "Ошибка ввода данных\n";
        
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return value;
            exit(1);
        }
    }
    return 0;
}

int main()
{
    float start;
    float finish;
    cout << "Введите начальную и конечную амплитуду: \n";
    start = controlInput();
    finish = controlInput();
    while (finish > start)
    {
        cout << "Некорректные значения! Введите данные заново.\n";
        start = controlInput();
        finish = controlInput();
    }

    int count = 0;

    while (start > finish)
    {
        start *= 1 - 0.084f;
        count++;
    }

    cout << "Маятник достигнет заданную апмлитуду через " << count << " колебаний.\n";
}