#include <iostream>

using namespace std;

#define SUMMER 1
//#define SPRING 1
//#define AUTUMN 1
//#define WINTER 1


#if defined(SUMMER)
    #define SEASON "Summer"
#elif defined(SPRING)
    #define SEASON "Spring"
#elif defined(AUTUMN)
    #define SEASON "Autumn"
#elif defined(WINTER)
    #define SEASON "Winter"
#else
    #define SEASON "Unknown season"
#endif

int main() 
{
    cout << "Current season: " << SEASON << endl;

}