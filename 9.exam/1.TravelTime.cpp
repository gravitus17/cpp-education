#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <cmath>

using namespace std;


string controlInput()
{
    while(true)
    {
        std::string value; 
        std::cin >> value;
    
        if (std::cin.fail() ||
            std::cin.peek() != '\n'|| 
            value.length() > 5||
            value[0] < 48 && value[0] > 50||
            value[0] == 48 && value[1] < 48 && value[1] > 52 ||
            value [1] < 48 && value [1] >57||
            value[2] != 58||
            value [3] < 48 && value[3] > 53 ||
            value [4] < 48 && value[4] >57
            )
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
    string departTime;
    string arriveTime;
    cout << "Input the depart time (HH:MM): ";
    departTime = controlInput();

    cout << "Input arrive time (HH:MM): ";
    arriveTime = controlInput();

    
    int hourDepart = stoi(departTime.substr(0, 2));
    int minuteDepart =stoi(departTime.substr(3, 2));

    int hourArrive = stoi(arriveTime.substr(0, 2));
    int minuteArrive = stoi(arriveTime.substr(3, 2));


    int hourDuration;
    int minuteDuration;

    if (hourArrive < hourDepart && minuteArrive < minuteDepart)
    {
        hourDuration = 24 + fabs(hourArrive - hourDepart);
        if (minuteArrive < minuteDepart)
        {
            minuteDuration = fabs(minuteArrive - minuteDepart + 60);
            hourDuration--;
        }
        else
            minuteDuration = minuteArrive - minuteDepart;   
    }
    else
    {
        hourDuration = hourArrive - hourDepart;
        if (minuteArrive < minuteDepart)
        {
            minuteDuration = fabs(minuteArrive - minuteDepart + 60);
            hourDuration--;
        }
        else
        {
            minuteDuration = minuteArrive - minuteDepart;
        }

    }

    cout << "The trip lasted " << hourDuration << " hours and " << minuteDuration << " minutes.\n";
    
}
