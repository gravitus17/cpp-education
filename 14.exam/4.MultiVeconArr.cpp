#include <iostream>
#include <vector>
using namespace std;

void multiply_vector_array(vector<float> vec_a, float arr[4][4] )
{
    vector<float> vec_c(4);
    float sum;
    for(int i = 0; i < 4; i++)
    {
        sum = 0;
        for(int g = 0; g < 4; g++)
        {
            sum += vec_a[g]*arr[i][g];
        }
        vec_c[i] = sum;
    }
    
    for(int i = 0; i < 4; i++)
        cout << vec_c[i] << ", ";
}

int main()
{
    vector<float> vec_a(4);
    float array[4][4];

    for(int i = 0; i < 4; i++)
    {
        cout << "Enter vector A:\n";
        cin >> vec_a[i];
        for(int g = 0; g < 4; g++)
            {
                cout << "enter Array:\n";
                cin >> array[i][g];
            }
    }


    multiply_vector_array(vec_a, array);

}