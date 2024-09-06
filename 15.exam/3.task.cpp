#include <iostream>
#include <vector>

using namespace std;

vector<int> vec_sort(vector<int> vec, int element)
{
    if (vec.size() < 5)
    {
        vec.push_back(element); 
        return vec;       
    }
    else
    {
        if (vec[4] >element && vec[3] <= element)
        {
            vec[4] = element; 
            return vec;      
        }
        else
            vec.push_back(element);

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0;  j < vec.size() -i -1; j++)
        {
            if(vec[j] >vec[j+1])
            {
            int temp = vec[j];
            vec[j] = vec[j+1];
            vec[j+1] = temp;
            }
        }
    }      
    }
    vec.pop_back();
    return vec;
}
int main()
{
   int user_input = 0;
   vector<int> vec;
   
   while(user_input != -2)
   {
        cout << "input number (-1 - display, -2 - finish porgram)\n";
        cin >> user_input;

        if (user_input == -1)
        {
                if (vec.size() < 5)
                {
                    cout << "the fifth number doesn't exist!\n";
                    continue;
                }
                else
                {
                    cout << vec[4] << endl;
                }
        }
        else if (user_input == -2)
            continue;
        else
            vec = vec_sort(vec, user_input);
   }

}