#include <iostream>
#include <string>
#include <numeric>
#include <limits>

using namespace std;

string controlInput()
{
    while(true)
    {
        string value; 
        std::cin >> value;
        bool err = false;

        for (int i = 0; i < value.length(); i++)
            if(value[i] < 49 || value[i] > 55)
            {
                err = true;
                break;
            }
        if (std::cin.fail() || std::cin.peek() != '\n'|| err) 
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

enum note
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};
int main()
{
    string accord;
    cout << "Input the accord number:\n";
    accord = controlInput();

    for (int i = 0; i < accord.length(); i++)
    {
        int note = accord[i] - '0';
        
        if (note & DO)
            cout << "DO";
        else if (note & RE)
            cout << "RE";
        else if (note & MI)
            cout << "MI";
        else if (note & FA)
            cout << "FA";
        else if (note & SOL)
            cout << "SOL";
        else if (note & LA)
            cout << "LA";
        else if (note & SI)
            cout << "SI";
    }


}