#include <iostream>
using namespace std;

int main()
{

    for (int row = 0; row < 20; row++)
    {
        for (int col = 0; col <50; col++)
        {
            if ( row == 10 && col != 49 && col != 25)
            {
                cout << "-";
            }
            else if  (col == 25 && row != 10 && row != 0)
            {
                cout << "|";
            }
            else if (row == 10 && col == 49 )
            {
                cout << ">";
            }
            else if (col == 25 && row == 10)
            {
                cout << "+";
            }
            else if (col == 25 && row == 0)
            {
                cout << "^";
            }
            else
            {
                cout << " ";
            }
        }
      cout << "\n";  
    }
        

}