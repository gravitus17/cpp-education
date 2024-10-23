#include <iostream>
#include <fstream>
#include <limits>
#include <numeric>
#include <ctime>
#include <cstdlib>

using namespace std;

int controlInput()
{
    while(true)
    {
        int value; 
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
        }
    }
    return 0;
}

int main()
{
    cout << "Enter width and length of the picture: ";
    int width = controlInput();
    int length = controlInput();
    

    ofstream picture("pic.txt", ios::binary);
    srand(time(nullptr));

    if(!picture)
    {
        cerr << "Error opening file!\n";
        return 1;
    }
    int num;

    for(int i = 0; i < length; i++)
    {
        num = rand() % 2;
        picture.write((char*)&num, width);
        picture.put('\n');
    }

    picture.close();
}