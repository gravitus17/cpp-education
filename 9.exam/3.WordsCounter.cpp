#include <iostream>
#include <string>

using namespace std;

int main()
{
    string user_input;
    
    cout << "Input words: ";
    getline(cin, user_input);

    int counter = 0;

    if (user_input.length() == 1 && user_input[0] == ' ')
        int counter = 0;
    else
    {
        for (int i = 0; i < user_input.length(); i++)
        {
            if (user_input[i] != ' ' && user_input[i+1] ==' '||
                user_input[i] != ' ' && i == user_input.length()-1 )
                counter++;
        }
    }
    cout << counter;
} 