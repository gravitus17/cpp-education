#include <iostream>
using namespace std;

int main()
{
    int width;
    int height;
    bool run = true;
    do{
    cout << "Введите высоту и ширину рамки: ";
    cin >> height >> width;
        if (width < 0 || height < 0)
        {
            cout << "вы ввели значение меньше 1.";
            continue;
        }
    run = false;
    }while(run);
    height--;
    width++;
    for (int row = 0; row <= height; row++)
    {
        for (int col = 0; col <= width; col++)
        {
            if (col == 0)
            {
                cout << "|";
            }
            else if  (col == width)
            {
                cout << "|\n";
            }
            else if (row == 0 || row == height)
            {
                cout << "-";
            }
            else
            {
                cout << " ";
            }
        }
        
    }
        

}