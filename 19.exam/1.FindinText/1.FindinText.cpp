#include <iostream>
#include <fstream>
#include <string>
#include <numeric>
#include <limits>

using namespace std;

string controlInput()
{
    while(true)
    {
        string value; 
        cin >> value;

        bool err = false;

        for (char c : value) {
            // Check if the character is not a uppercase or  lowercase letter
            if (!std::isupper(c) && !std::islower(c)) {
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
}

void findWord(string fword, ifstream & f)
{
    f.open ("words.txt");
    int counter = 0;
    string word;

    while(!f.eof())
    {
        f >> word;
        if (word == fword)
        {
            counter++;
        }
        word.clear();
    }
    f.close();
    cout << " Number of match in text of the word " << "'" << fword << "'" << " is " << counter << endl; 
}

int main()
{
    ifstream words;

    cout << "Input the word\n";
    string seek_word = controlInput();

    findWord(seek_word, words);
}