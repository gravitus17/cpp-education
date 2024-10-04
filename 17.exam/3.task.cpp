#include <iostream>
#include <cstring>

using namespace std;

bool substr (const char* str,const char* substr)
{
     int strLen = strlen(str);
    int substrLen = strlen(substr);

    for (int i = 0; i <= strLen - substrLen; i++) {
        int j;
        for (j = 0; j < substrLen; j++) {
            if (str[i + j] != substr[j]) {
                break;  // mismatch found
            }
        }
        if (j == substrLen) {
            return true;  // substring found at index i
        }
    }
    return false;  // substring not found
}


int main()
{
    const char* a = "Hello, my dear friend, i would like to play a game with you";
    const char* b = "ke to";
    const char* c = "Hfllo, my";

    cout << substr(a,b) << " " << substr(a,c) << endl;
}