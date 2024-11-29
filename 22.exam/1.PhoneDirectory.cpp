#include <iostream>
#include <map>
#include <string>
#include <regex>
#include <vector>

using namespace std;

map <string, string> phoneDirectory;

void addNumber(string& number, string& name)
{
    pair <string, string> phoneNumber(number, name);
    phoneDirectory.insert(phoneNumber);

}

void findPhoneByName(string& lastname)
{   
    for (map <string, string>::iterator it = phoneDirectory.begin();
        it != phoneDirectory.end(); it++)
    {
        if (lastname == it -> second)
            cout << it->first << " ";
    
    }
    cout << endl;
}

void findNameByPhone (string& number)
{
     for (map <string, string>::iterator it = phoneDirectory.begin();
        it != phoneDirectory.end(); it++)
    {
        if (number == it -> first)
            cout << it->second << endl;
            break;
    }
}

int main()
{
    string user_input;
    while(true)
    {
        cout << "enter: ";
        getline(cin, user_input);
        if(user_input.empty())
            continue;

        istringstream iss(user_input);
        string firstWord;
        iss >> firstWord;

        if (std::regex_match(firstWord, regex("^[0-9]{2}-[0-9]{2}-[0-9]{2}$"))) {
            // It's a phone number entry
            std::string lastName;
            iss >> lastName;
            addNumber(firstWord, lastName);
        } else if (regex_match(firstWord, regex("^[A-Za-z]+$"))) {
            // It's a last name query
            findPhoneByName(firstWord);
        } else {
            // Assume it's a phone number query
            findNameByPhone(firstWord);
        }

        char exit;
        cout << "Finish program ? y/n?\n";
        cin >> exit;
        if (exit == 'y')
            return 0;

    }
}