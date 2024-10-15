#include <iostream>

using namespace std;

void eventdigit(long long n, int& a)
{
    if (n == 0)
        cout << a << endl;
    else
    {
        if((n % 10) % 2 == 0)
        {
            a++;
        }
        eventdigit( n/10, a);
    }

}
int main()
{
    int ans = 0;
    eventdigit(9223372036854775806, ans);

}