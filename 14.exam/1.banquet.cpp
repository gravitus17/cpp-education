#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int guess[12][3] = {{4, 3, 1}, {4, 3, 1},
                        {3, 2, 1}, {3, 2, 1},
                        {3, 2, 1}, {3, 2, 1},
                        {3, 2, 1}, {3, 2, 1},
                        {3, 2, 1}, {3, 2, 1},
                        {3, 2, 1}, {3, 2, 1}};

    guess[4][2]+=1;
    guess[2][0] -=1;
    guess[0][0] -=1;
    guess[2][0] +=1;
    guess[0][1] -=1;
    
    for (int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 3; j++)
            {
                cout << guess[i][j] << " ";
            }
        cout << endl;
    }   
        
}