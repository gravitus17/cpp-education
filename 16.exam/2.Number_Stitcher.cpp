#include <iostream>
#include <string>

using namespace std;

int main()
{
    double n;
    string dec;
    string fraction;



    cout << "Input integer and fraction part of number: ";
    cin >> dec;
    cout << ".";
    cin >> fraction;

    string number = dec + "." + fraction;

    n = stod(number);
    cout << n;
}