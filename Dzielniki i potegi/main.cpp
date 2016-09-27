#include <iostream>

using namespace std;

bool czypot(int l)
{
    for(int i = 2; i*i<=l; i++)
    {
        int pod = i;
        int wykl = 1;
        while(pod < l)
        {
            pod = pod * i;
            wykl++;
        }
        if(pod==l)
            return 1;
    }
    return 0;
}

int main()
{
    int l;
    cin >> l;
    for(int i=1; i*i<l; i++)
    {
        if(l%i==0)
        {
            if(czypot(i) == 1)
                cout<<i<<endl;
            if(czypot(l/i) == 1)
                cout<<l/i<<endl;
        }
    }
    return 0;
}
