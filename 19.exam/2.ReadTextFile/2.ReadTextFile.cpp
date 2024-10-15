#include <iostream>
#include <fstream>
#include <numeric>
#include <limits>
#include <vector>

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
            if (!std::isupper(c) && !std::islower(c) && !isdigit(c) && !ispunct(c)) {
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



int main()
{
    cout << "Input file name path\n";
    string filename = controlInput();

    ifstream text(filename,ios::binary);

    //Check correct path
    while(!text.is_open())
    {
        filename.clear();

        filename = controlInput();
    }

    const size_t bufferSize = 1024; 
    vector<char> buffer(bufferSize); // Create a buffer to hold the data

    while (true) {
        text.read(buffer.data(), buffer.size());
        
        // Get the number of bytes actually read
        streamsize bytesRead = text.gcount();

        // If no bytes were read, break the loop
        if (bytesRead <= 0) {
            break;
        }


        cout.write(buffer.data(), bytesRead);
    }


    text.close();

}