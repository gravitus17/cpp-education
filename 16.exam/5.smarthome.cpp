#include <iostream>
#include <sstream>
#include <limits>
#include <string>
#include <cctype>

using namespace std;

string controlInput()
{
    while(true)
    {
        string value; 
        getline(cin, value);

        bool err = false;
        if (value.find(' ') == string::npos)
            err = true;

        for (char c : value) {
            // Check if the character is not a digit (0-9) or a lowercase letter (a-z)
            if (!std::isdigit(c) && !std::islower(c)&& !isspace(c)&& c != '-' ) {
                err = true;
                break;
            }
            }
        if (err) 
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

enum switches 
{
    LIGHTS_INSIDE = 1, 
    LIGHTS_OUTSIDE = 2, 
    HEATERS = 4, 
    WATER_PIPE_HEATING = 8, 
    CONDITIONER = 16 
};

int main()
{
    int total_day = 0;
    string buffer;
    int color_temperature = 5000;
    int hours = 0;
    int switches_state = 0;
    do
    {
        string movement;
        string light;
        int temp_outside;
        int temp_inside;
        cout << "Temperature inside, temperature outside, movement, lights:\n";

        buffer = controlInput();
        stringstream buffer_stream(buffer);
        buffer_stream >> temp_inside >> temp_outside >> movement >> light;

        //check correct input
        if (movement != "yes" && movement != "no" ||
            light != "on"&& light != "off")
        {
            cout << "wrong input!\n";
            continue;
        }

        //Switches
        if (temp_outside < 0 && (switches_state & WATER_PIPE_HEATING) ==false)
        {
            switches_state |= WATER_PIPE_HEATING;
            cout << "Water pipe heater ON!\n";
        }
        else if (temp_outside > 5 && switches_state & WATER_PIPE_HEATING)
        {
            switches_state &= ~WATER_PIPE_HEATING;
            cout << "water pipe heater OFF!\n";
        }

        if(temp_inside < 22 && (switches_state & HEATERS) == false)
        {
            switches_state |= HEATERS;
            cout << "Heaters ON!\n";
        }
        else if(temp_inside >= 25 && switches_state & HEATERS)
        {
            switches_state &= ~HEATERS;
            cout << "Heaters OFF!\n";
        }

        if (temp_inside >=30 && (switches_state & CONDITIONER) == false)
        {
            switches_state |= CONDITIONER;
            cout << "Conditioner ON!\n";
        }
        else if (temp_inside <=25 && switches_state & CONDITIONER)
        {
            switches_state &= ~CONDITIONER;
            cout << "Conditioner OFF!\n";
        }

        if( hours < 5 && hours >16 && movement == "yes" && (switches_state & LIGHTS_OUTSIDE) ==false)
        {
            switches_state |= LIGHTS_OUTSIDE;
            cout << "Outside light ON!\n";
        }
        else if (switches_state & LIGHTS_OUTSIDE)
        {
            switches_state &= ~LIGHTS_OUTSIDE;
            cout << "Outside light OFF!\n";
        }

        if (light == "on" && (switches_state & LIGHTS_INSIDE) == false)
        {
            switches_state |= LIGHTS_INSIDE;
            cout << "Inside light ON!\n";
        }
        else if (light == "off" && switches_state & LIGHTS_INSIDE)
        {
            switches_state &= ~LIGHTS_INSIDE;
            cout << "Inside light OFF!\n";
        }

        //temperature color
        if (hours >=16 && hours <= 20)
        {
            color_temperature -= 575;
        }
        else if (hours == 0 )
            color_temperature = 5000;

        if (switches_state & LIGHTS_INSIDE)
            cout << "Color temperature: " << color_temperature <<"K\n";
        
        // day counter;
        hours++;
        if (hours == 24)
    
        {
            total_day++;
            hours = 0;
        }

    } while (total_day != 2);
    

    
}