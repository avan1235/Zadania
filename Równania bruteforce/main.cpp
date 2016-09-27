#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    bool check = 0;
    int num;

    for(double i = 0; i < 200; i++)
            if(((int)(pow((double)7, (double)i))-1)%3 == 0)
            {
                check = 1;
                num = i;
            }


    if(check)
        cout << "Tak, dla n=" << num;
    else
        cout << "Nie";

    return 0;
}
