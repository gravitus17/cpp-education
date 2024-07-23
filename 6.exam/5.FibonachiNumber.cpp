#include <iostream>
using namespace std;

int main()
{
    int number;
    std::cout << "Введите номер последовательности: ";
    cin >> number;

    int counter = 0;
    int fib1 = 1;
    int fib2 = 1;
    int fibcurrent;
    while (counter < number)
    {
      
    
        if (counter <2)
        {
            fibcurrent = 1;
        }
        else
        {
            fibcurrent = fib1 + fib2;
        }
        counter++;
        fib2 = fib1;
        fib1 = fibcurrent;
    }

    std::cout << "Число в последовательности: " << fibcurrent << endl;
}
    