#include <iostream>
#include <cmath>

using namespace std;

bool is_less (double a, double b, double epsilon) {
       return (a < (b - epsilon));
    }

bool isRelativelyEqual(double lhs, double rhs, double epsilon) 
{
   return abs(lhs - rhs) < epsilon;
}

int main()
{
    float speed = 0.0;
    float speed_delta;
    char speed_str[5];

    do
    {
        cout <<  "Speed delta: ";
        cin >>  speed_delta;

        if ( speed + speed_delta <isRelativelyEqual(speed, 0.0, 0.01)||
        speed + speed_delta >150 )
        {
            cout << "Wrong input!\n";
            continue;
        }
        speed += speed_delta;
        sprintf(speed_str, "%.1f", speed);  
        cout << "Speed: " << speed_str << endl;



    } while (speed > 0.1);
    
}