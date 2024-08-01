#include <iostream>
#include <string>

using namespace std;

string encrypt_Ceasar(int k, string text)
{
    if (k < 0)
        cerr << "Wrong code.\n";
        exit(1);

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] >= 'A' && text[i]<='Z')
        {
            text[i] =  (text[i] -'A' + k )%26 + 'A';
        }
        else if(text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] =  (text[i] -'a' + k )%26 + 'a';
        }
    }
    return text;
}

int main()
{
    string encrypt;
    int code;
    cout << "input text: ";
    getline(cin, encrypt);

    cout << "code: ";
    cin >> code;

    cout << encrypt_Ceasar(code, encrypt);
}