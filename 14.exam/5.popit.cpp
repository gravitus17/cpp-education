#include <iostream>
#include <vector>

using namespace std;

void initial_pimple( bool pimple[][12])
{
    for(int i = 0; i < 12; i++)
        for(int g =0; g < 12; g++)
        {
            pimple[i][g] = true;
        }
}
void pimple_draw(bool arr[][12])
{
        for(int i = 0; i < 12; i++)
    {
        for(int g =0; g < 12; g++)
        {
            if(arr[i][g])
                cout << "O";
            else
                cout << "X";
        }
        cout << endl;
    }
}

int popit(bool pimple[][12],int XY_begin[2], int XY_end[2])
{
    int counter = 0;
    for( int i = XY_begin[1]; i <= XY_end[1]; i++)
        for(int g = XY_begin[0]; g <= XY_end[0]; g++)
        {
            if (pimple[i][g])
            {
                cout << "POP!\n";
                pimple[i][g] = false;
                counter++;
            }
        }
        return counter;
}

void pimple_pop_it (bool pimple[][12])
{
    
    bool finish = true;
    int XY_begin[2];
    int XY_end[2];
    int pop_counter;

    initial_pimple(pimple);
    while(finish)
    {
        pimple_draw(pimple);

        cout << "enter X and Y begin:\n";
        cin >> XY_begin[0] >> XY_begin[1];
        if(XY_begin[0] < 0 || XY_begin[0] > 11 &&
            XY_begin[1] < 0 || XY_begin[0] >11)
        {
            cout << "Invalid input.\n";
            continue;
        }
        
        cout << "enter X and Y end:\n";
        cin >> XY_end[0] >> XY_end[1];
        if (XY_end[0] < 0|| XY_end[0] >11 &&
            XY_end[1] < 0|| XY_end[1] >11 ||
            XY_end[0] < XY_begin[0] || XY_end[1] < XY_begin[1])
        {
            cout << "Invalid input.\n";
            continue;
        }
        pop_counter +=popit(pimple, XY_begin, XY_end);
        if(pop_counter == 12*12)
            finish = false; 
    }
    cout << " end!\n";

}
int main()
{
    bool pimple[12][12];
    pimple_pop_it(pimple);
}

    





    

    

