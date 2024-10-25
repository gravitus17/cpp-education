#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Mathvector
{
   double x;
   double y;

    Mathvector add(Mathvector& vec1, Mathvector& vec2)
    {
        Mathvector result;
        result.x = vec1.x + vec2.x;
        result.y = vec1.y + vec2.y;
        return result;
    }
    Mathvector subtract(Mathvector& vec1, Mathvector& vec2)
    {
        Mathvector result;
        result.x = vec1.x - vec2.x;
        result.y = vec1.y - vec2.y;
        return result;
    }
    Mathvector scale(Mathvector& vec, double scalar)
    {
        Mathvector result;
        result.x = vec.x * scalar;
        result.y = vec.y * scalar;

    }
    double length(Mathvector& vec)
    {
        double length = sqrt(vec.x * vec.x + vec.y * vec.y);
        return length;
    }
    Mathvector normalize(Mathvector& vec)
    {
        double len = length(vec);
        Mathvector result;
        if (len == 0)
        {
            cout << "Can't normalize  a zero vector\n";
            result.x = 0;
            result.y =0;
            return result;
        }
        else
        {
            result.x = vec.x/len;
            result.y = vec.y/len;
            return result;
        }
    }
};
int main()
{
    while (true)
    {
        string input;
        cout << "input Operation with vector:\n'add' - add two vector" <<
            "\n'subtract' - subtract two vector" <<
            "\n'scale' - multiply scalar on vector"<<
            "\n'length' - return length of vector" <<
            "\n'normalize' - normalize vector\nexit - end program\n";

        cin >> input;
        if( input == "add")
        {
            Mathvector vec1;
            Mathvector vec2;
            cout << "Input vector data:";
            cout << "vector 1 xy: ";
            cin >> vec1.x >> vec1.y;
            
            cout << "vector 2 xy: ";
            cin >> vec2.x >> vec2.y;
            Mathvector result =  result.add(vec1, vec2);
            cout.precision(4);
            cout << "Result: "  <<result.x << " " << result.y << endl;
        }
        else if ( input == "subtract")
        {
            Mathvector vec1;
            Mathvector vec2;
            cout << "Input vector data: ";
            cout << "vector 1 xy: ";
            cin >> vec1.x >> vec1.y;
            
            cout << "vector 2 xy: ";
            cin >> vec2.x >> vec2.y;
            Mathvector result =  result.subtract(vec1, vec2);
            cout.precision(4);
            cout << "Result: " << result.x << " " << result.y << endl; 
        }
        else if (input == "scale")
        {
            Mathvector vec;
            cout << "Input vector data:";
            cout << "vector xy: ";
            cin >> vec.x >> vec.y;
            
            double scalar;
            cout << "input scalar: ";
            cin >> scalar;
            Mathvector result =  result.scale(vec, scalar);
            cout << "Result: " << setprecision(5) << result.x << " " << result.y << endl; 
        }

        else if (input == "length")
        {
            Mathvector vec;
            cout << "Input vector data:";
            cout << "vector xy: ";
            cin >> vec.x >> vec.y;
            cout.precision(4);
            double len = vec.length(vec);
            cout << "Length of vector: " << len << endl;
        }
        else if( input == "normalize")
        {   
            Mathvector vec;
            cout << "Input vector data:";
            cout << "vector xy: ";
            cin >> vec.x >> vec.y;
            cout.precision(4);
            Mathvector result = vec.normalize(vec);
            cout << "Result: " << result.x << " " << result.y << endl;
        }
        else if(input == "exit")
            break;
        else
        {
            cout << "Wrong input!\n";
        }
    }
}
