#include <iostream>

using namespace std;

string get_address_part(string ip_address, int octa_order )
{
    string octa;
    int counter = 0;
    for (int i = 0; i < ip_address.length(); i++)
    {
        if (ip_address[i] == '.')
        {
            counter++;
            if (ip_address[i-1] == '.' || counter > 4) 
                return "Invalid";
            else if (counter > octa_order)
                return octa;
        }
        else if (ip_address[i] != '.' && counter == octa_order)
        {
            if ( ip_address[i] >= '0' && ip_address[i] <= '9' ||
                i == 0 && ip_address[i] != '0'|| 
                ip_address[i-1] == '.' && ip_address[i] == '0'&& ip_address[i+1] == '.'||
                i == ip_address.length() -1 && ip_address[i] == '0')
                {
                    octa += ip_address[i];
                }
            else
                return "Invalid";    
        } 
    }
}

string valid_ip(string ip_address)
{
    for (int i = 0; i < 4; i++)
    {
        string ip_part = get_address_part(ip_address, i);
        if (ip_part == "Invalid")
            return ip_part;
        else if (ip_part.length() > 3 || stoi(ip_part) > 255)
            return "Invalid";
    }
    return "Valid";

}
int main()
{
    string ip4;
    cout << "Input your IP-address: ";
    cin >> ip4;

    cout << valid_ip(ip4);
}