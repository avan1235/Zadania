#include <iostream>

using namespace std;

int nwd(int a, int b)
{
    if((a%b)!=0)
    {
        int c = a % b;
        a = b;
        b = c;
        nwd(a, b);
    }
    else
        {
        return b;
    }
}

int nwd1(int a, int b)
{
    if(a==b)
        return a;
    else if(a>b)
        nwd1(a-b, b);
    else if(a<b)
        nwd1(a, b-a);
}
int nwd2()
{
    if(b!=0)
    {
        return nwd2(b, a%b);
    }
    return a;
}
int main()
{
    int a, b;
    cin >> a >> b;
    int nwdl = nwd(a, b);

    cout << nwdl;

    return 0;
}
