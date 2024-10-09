#include <iostream>
#include <vector>

using namespace std;

void swapvec(vector<int>& vec1, vector<int>& vec2)
{   
    int a;
    if ( vec1.size() > vec2.size())
    {
       for (int i = 0 ; i < vec2.size(); i++)
       {
        int a = vec2[i];
        vec2[i] = vec1[i];
        vec1[i] = a;
       }
    }
    else
    {
        for(int i = 0; i < vec1.size(); i++)
        {
        int a = vec1[i];
        vec1[i] = vec2[i];
        vec2[i] = a;
        }
    }
}

int main()
{
    vector<int> a = {144, 121, 100, 81, 64, 49, 36};
    vector<int> b = {1, 4, 9, 16, 25 };

    swapvec(a, b);

    for( auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;

  

    for( auto i : b)
    {
        cout << i << " ";
    }
    cout << endl;

}