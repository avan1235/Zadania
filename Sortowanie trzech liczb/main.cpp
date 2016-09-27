#include <iostream>

using namespace std;

int main()
{
    int p, d, t;
    cin >> p >> d >> t;

    if(p > d)
    {
        if(p > t)
        {
            if(t > d)
            {
                cout << d << ", " << t << ", " << p;
            }
            else // t <= d
            {
                cout << t << ", " << d << ", " << p;
            }
        }
        else // p <= t
        {
            cout << d << ", " << p << ", " << t;
        }

    }
    else // p <= d
    {
        if(d > t)
        {
            if(t > p)
            {
                cout << p << ", " << t << ", " << d;
            }
            else // t <= p
            {
                cout << t << ", " << p << ", " << d;
            }
        }
        else // d <= t
        {
            cout << p << ", " << d << ", " << t;
        }
    }

    return 0;
}
