#include <iostream>
#include <string>
#include <tuple>

using namespace std;

string correct_email_before(string email)
{   
    string correct_email;
    string allow_symbol = "!#$%&'*+-/=?^_`{|}~.0123456789";
    if (email.length() > 124)
        return "No";
 
    for (int i =0; i < email.length(); i++)
    {
        if (email[i] == '@')
        {
            correct_email += email[i];
            return correct_email;
             
        }
        else if (email[i] == '.' && email[i+1] =='.'||
            i == 0 && email[i] == '.'||
            email[i+1] == '@' && email[i] == '.')
        {
            return "No";
        }
        else if (correct_email.length() > 64)
            return "No";
        
        else
        {
            for( int l = 0; l < allow_symbol.length(); l++)
            {   
                
                if (allow_symbol[l] == allow_symbol[i]||
                     email[i] >= 'A' && email[i] <= 'Z' ||
                    email[i] >= 'a' && email[i] <= 'z')
                {
                    break;
                }
                else if ( l == allow_symbol.length()-1 && allow_symbol[l] != email[i] )
                    return "No";
            }   

        }
        correct_email += email[i];
    }
    return "No";
}

string correct_email_after(string first_part, string email)
{
    string allow_symbol = "-.0123456789";
    if (email.length() - first_part.length() > 63)
        return "No";

    for (int i = first_part.length(); i < email.length(); i++)
    {
        if (email[i] == '.' && email[i-1] =='.'||
            i == email.length() -1 && email[i] == '.'||
            email[i-1] == '@' && email[i] == '.'||
            email[i]== '@')
        {
            return "No";
        }
        else
        {
            for( int l = 0; l < allow_symbol.length(); l++)
            {
               if (allow_symbol[l] == email[i]||
                     email[i] >= 'A' && email[i] <= 'Z' ||
                    email[i] >= 'a' && email[i] <= 'z')
                {
                    break;
                }
                else if ( l == allow_symbol.length()-1 && allow_symbol[l] != email[i] )
                    return "No";
            }
            
        }
        first_part+= email[i];
    }
    return first_part;
}

int main()
{
    string mail;

    cout << "Input your email: ";
    cin >> mail;

    if (correct_email_before(mail) == "No" ||
        correct_email_after(correct_email_before(mail), mail) == "No")
        cout << "No\n";
    else
    {
        cout << correct_email_after(correct_email_before(mail), mail) << "\nYes\n";
    }
    
}