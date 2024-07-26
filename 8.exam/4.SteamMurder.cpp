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
    float download = 0;
    int second = 0;
    cout << "Ввод:\nУкажитеразмер файла для скачивания: ";
    float fileSize = controlInput();

    cout << "Укажите скорость скачивания: ";
    float internetSpeed = controlInput();

    while (download < fileSize)
    {
        int percent = 0;
        second++;

        if ( download + internetSpeed > fileSize)
        {
            download += (fileSize-download);
        }
        else
            download += internetSpeed;

        percent = (download*100 / fileSize);
        cout << "Вывод:\nПрошло " << second << " сек. Скачано " 
            << download << " из " << fileSize << "МБ.(" << percent <<"%)\n";
        
    }
}
