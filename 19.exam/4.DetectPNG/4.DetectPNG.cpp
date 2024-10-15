#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <numeric>

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

    ifstream png_file(filename,ios::binary);

    //Check correct path
    while(!png_file.is_open())
    {
        filename.clear();

        filename = controlInput();
    }

    char c[4];
    int buffer;
    png_file.read(c, sizeof(c));
    
    if( int(c[0] != -119 &&
            c[1] != 'P' &&
            c[2] != 'N' &&
            c[3] != 'G'))
    {
        cout << " Not PNG file!\n";
    }
    else
        cout << "PNG file!\n";
    
    png_file.close();

}