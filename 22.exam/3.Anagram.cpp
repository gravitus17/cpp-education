#include <iostream>
#include <map>
#include <string>
#include <limits>
#include <numeric>

using namespace std;

string controlInput()
{
    while(true)
    {
        string value; 
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "error input\n";
        
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return value;
        }
    }
}

bool isAnagram(string str1, string str2)
{
    if( str1.length() !=str2.length())
     return false;

    map <char, int> charCount;

    for( char c : str1)
    {
        charCount[c]++;

    }
    for (char c : str2)
    {
        charCount[c]--;

        if(charCount[c] < 0)
            return false;
    }

    return true;
}

int main()
{
    string user_input;
    while (true)
    {
        string str1, str2;
        cout << "Input first word: ";
        str1 = controlInput();
        
        cout << "Input second word: ";
        str2 = controlInput();

        if (isAnagram(str1, str2))
            cout << boolalpha << true << endl<< str2 << " is anagram of" << str1 << endl;
        else 
            cout << boolalpha << false << endl << str2 << " is not anagram of" << str2 << endl;

        cout << "End program ? yes\\no?";
        user_input = controlInput();
        if (user_input == "yes")
            break;
        else if (user_input == "no")
            continue;;
    }
}