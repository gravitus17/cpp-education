#include <iostream>

using namespace std;

int rabbitJump( int n,int k = 3)
{

    if (k==0 || k==n)
        return 1;
    else
        return rabbitJump(n-1,k-1)+rabbitJump(n-1,k);
}

int main()
{
    cout << rabbitJump(9,2);
}