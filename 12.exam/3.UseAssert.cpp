#include <iostream>
#include <cassert>
#include <limits>
#include <numeric>

using namespace std;


float controlInput()
{
    while(true)
    {
        float value; 
        std::cin >> value;
    
        if (std::cin.fail() || std::cin.peek() != '\n')
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

float travelTime(float distance, float speed)
{
    assert(speed > 0);
    
    float travel_time = distance / speed;

    return travel_time;
    
}
int main()
{
    float speed = controlInput();
    float distance = controlInput();

    cout << travelTime(distance, speed);
}