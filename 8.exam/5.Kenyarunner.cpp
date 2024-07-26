#include <iostream>
#include <numeric>
#include <limits>
#include <cmath>

using namespace std;

float controlInput()
{
    while(true)
    {
        int value; 
        std::cin >> value;
    
        if (std::cin.fail() || std::cin.peek() != '\n'|| value <= 0)
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
    cout << "Ввод:\nПривет, Сэм! Сколько километров ты сегодня пробежал?";
    int samDistance = controlInput();
    int samPace = 0;
    float averagePace;

    for (int i = 1; i <=samDistance;i++)
    {
        cout << "Какой у тебя был темп на километре " << i << "?\n";
        samPace += controlInput();   
    }
    averagePace = round(samPace/samDistance);

    cout << "Вывод:\nТвой средний темп за тренировку: " << int(averagePace)/60
        << " минуты " << int(averagePace)%60 << " секунд.\n";

}