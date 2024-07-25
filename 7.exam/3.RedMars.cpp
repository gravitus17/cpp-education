#include <iostream>
using namespace std;

int main()
{
    int width = 15;
    int length = 20;
    int robotPosition[2] = {7,10};
    bool run = true;
    std::string command;

    while(run)
    {
        cout << "[Программа]: Марсоход на позиции " << robotPosition[0] << ", " << robotPosition[1]
            << ", введите комманду:\n";
        cout << "[Оператор]: ";
        cin >> command;

        if (command == "a")
        {
            if(robotPosition[0] == 0)
            {
                cout << "[Программа]: Марсоход уперся в стену.\n";
                continue;
            }
            robotPosition[0]--;
        }

        else if (command == "d")
        {
            if(robotPosition[0] == 15)
            {
                cout << "[Программа]: Марсоход уперся в стену.\n";
                continue;
            }
            robotPosition[0]++;
        }
        else if (command == "s")
        {
            if(robotPosition[1] == 0)
            {
                cout << "[Программа]: Марсоход уперся в стену.\n";
                continue;
            }
            robotPosition[1]--;
        }
        else if (command == "w")
        {
            if(robotPosition[1] == 20)
            {
                cout << "[Программа]: Марсоход уперся в стену.\n";
                continue;
            }
            robotPosition[1]++;
        }
        else if (command == "help")
        {
            cout << "[Программа]: Доступные комманды:\n\
                    a — двигать марсоход на восток\n\
                    w — двигать марсоход на север\n\
                    s — двигать марсоход на юг\n\
                    d — двигать марсоход на восток\n\
                    help — вывести возможные комманды\n\
                    x — выйти из программы\n";
        }
        else if (command == "x")
        {
            cout << "[Программа]: Завершение программы.\n";
            run = false;
        }
        else
        {
            cout << "[Программа]: Недоступная комманда. Для вывода возможных комманд введите 'help'\n";
        }
        
    }
}