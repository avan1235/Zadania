#include <iostream>

using namespace std;

int nwd_z_liczb(int a, int b)
{
    int c;
    while(b != 0)
    {
        c = a%b;
        //cout << a << "%" << b << "=" << c;
        a = b;
        //cout << " a=" << a;
        b = c;
        //cout << " b=" << b << endl;
    }
    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int NWD = nwd_z_liczb(a, b);

    cout << NWD;
    return 0;
}
