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

    int cubSize = 5;
    int cubSum;
    int cubSet;

    cout << "Введите размер бруска: ";
    cout << "X: ";
    float x = controlInput();
    cout << "Y: ";
    float y = controlInput();
    cout << "Z: ";
    float z = controlInput();

    if (x < cubSize || y < cubSize || z < cubSize)
    {
        cout << "Невозможно создать кубики из данного бруска.\n";
        return 1;
    }
    else
    {
        cubSum = int((x/cubSize)*(y/cubSize)*(z/cubSize));
        cout << "Вывод:\nИз этого бруска можно сделать " << cubSum << " кубиков.\n";
        cubSet = cubSum/3*3;
        if (cubSum < 8)
            cout << "Невозможно составить набор.\n";
        else
            cout << "Из них можно составить набор из " << cubSet << " кубиков.\n";
    }

}   