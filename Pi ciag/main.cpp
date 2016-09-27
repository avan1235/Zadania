#include <iostream>
#include "math.h"

using namespace std;

int main()
{
    double x, n;

    cin >> x;
    cin >> n;

    cout << "I: ";
    double sum = 0;
    for(double m = n; m > 0; m--)
    {
        sum = sum + m*(pow(x,(m-1)));
    }
    cout << sum << endl;
    cout << "II: " << (n * (pow(x, (n+1)))-((n+1)*(pow(x,n)))+1)/(pow((x-1),2));

    return 0;
}
