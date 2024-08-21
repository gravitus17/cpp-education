#include <iostream>
#include <string>

using namespace std;

int main()
{
    string flat[10];
    int apart_num;
    for ( int i = 0; i < 10; i++)
    {
        cin >> flat[i];
    }

    string user_input;
    while (true)
    {
        cout << "Input apart number: ";
        cin >> apart_num;
        if (apart_num < 1 || apart_num > 10)
        {
            cerr << "invalid data\n";
            continue;
        }
        apart_num--;
        cout << flat[apart_num] << endl;

        cout << "Do you like finish program ? y/n\n";
        cin >> user_input;
        if (user_input == "y")
            break;
    }
}