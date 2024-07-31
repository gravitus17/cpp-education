#include <iostream>
#include <string>

using namespace std;

int main() {
   string number;
   cin >> number;

   bool minus = number.length() > 0 && number[0] == '-';
   cout << minus;

   int dotCount = 0; 
   int numberCount = 0; 
   bool charsCorrect = true; 
   for(int i = minus ? 1 : 0; i < number.length(); ++i) 
    {
       if(number[i] >= '0' && number[i] <= '9') 
       {
           numberCount++;
           continue; 
       }

       if(number[i] == '.') 
       {
           dotCount++;
           continue; 
       }
       charsCorrect = false;
       break;
   }
   
   cout << (charsCorrect && (numberCount > 0) && (dotCount <= 1) ?
                   "Yes" :
                   "No"
               ) << '\n';
}