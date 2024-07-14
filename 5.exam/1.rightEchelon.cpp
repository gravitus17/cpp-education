#include <iostream>
using namespace std;

int main()
{
    int planeSpeed;
    int planeHeight;

    cout << "Введите скорость самолета: ";
    cin >> planeSpeed;

    cout << "Введите высота полета самолета: ";
    cin >> planeHeight;

    if ((planeSpeed >= 750 && planeSpeed <= 850) && (planeHeight >= 9000 && planeHeight <= 9500))
    {
        cout << "Самолет успешно долетит\n";
    }
    else
    {
        cout << "Самолет разобъется!!!\n";
    }
}