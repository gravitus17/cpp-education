#include <iostream>

using namespace std;

void matrix_comparison(int arr_A[][4], int arr_B[][4])
{
    for(int i = 0; i < 4; i++)
        for(int g = 0; g < 4; g++)
        {
            if (arr_A[i][g] != arr_B[i][g])
            {
                cout <<  "matrix are unequal!\n";
                return;
            }
            else
            {
                if(i != g)
                {
                    arr_A[i][g] =0;
                }
                
            }
        }

    for(int i = 0; i < 4; i++)
    {
        for(int g = 0; g < 4; g++)
            cout << arr_A[i][g];
        cout << endl;
    }   
}

int main()
{
    int matrix_A[4][4];
    int matrix_B[4][4];

    cout << "Input matrix A & B:\n";
    for(int i = 0; i < 4; i++)
        for(int g = 0; g < 4; g++)
            cin >> matrix_A[i][g] >> matrix_B[i][g];

    matrix_comparison(matrix_A, matrix_B);

}