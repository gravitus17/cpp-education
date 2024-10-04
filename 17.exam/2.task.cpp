#include <iostream>

using namespace std;


void sort(int* a)
{
    for( int i = 0; i < 10/2; i++)
    {   int c = *(a +i);
       *(a+i) = *(a +(9 - i));
       *(a+(9-i)) = c;
    }
}
int main()
{
int ar[10] = {12, 13, 14, 15, 19, 21, 23, 25, 30, 33};
sort(ar);
cout << &ar << endl;
}
