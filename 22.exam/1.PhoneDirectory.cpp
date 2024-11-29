#include <iostream>
#include <map>
#include <string>
#include <regex>
#include <vector>

using namespace std;

multimap <string, string> phoneDirectory;
multimap <string, string> nameDirectory;

void addNumber(string& number, string& name)
{
    
    phoneDirectory.insert({number, name});
    nameDirectory.insert({name, number});

}

void findPhoneByName(const string& lastname) 
{
    auto range = nameDirectory.equal_range(lastname);
    if (range.first != range.second) {
        for (auto it = range.first; it != range.second; ++it) {
            cout << it->second << " "; // Output the phone number
        }
        cout << endl;
    } else {
        cout << "No phone number found for " << lastname << endl;
    }
}

void findNameByPhone(const string& number) 
{
    auto range = phoneDirectory.equal_range(number);
    if (range.first != range.second) {
        for (auto it = range.first; it != range.second; ++it) {
            cout << it->second << " "; // Output the name
        }
        cout << endl;
    } else {
        cout << "No name found for phone number " << number << endl;
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
        string secondWord;
        iss >> secondWord;

        if (regex_match(firstWord, regex("^[0-9]{2}-[0-9]{2}-[0-9]{2}$"))&& !secondWord.empty())
        {
            // It's a phone number entry
            addNumber(firstWord, secondWord);
        } 
        else if (regex_match(firstWord, regex("^[A-Za-z]+$"))) 
        {
            // It's a last name query
            findPhoneByName(firstWord);
        } 
        else 
        {
            // Assume it's a phone number query
            findNameByPhone(firstWord);
        }

        char exit;
        cout << "Finish program ? y/n?\n";
        cin >> exit;
        cin.ignore();
        if (exit == 'y')
            break;

    }
    return 0;
}