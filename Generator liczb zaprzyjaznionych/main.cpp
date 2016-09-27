#include <iostream>

using namespace std;

int suma_dzielnikow(int l)
{
    int sd = 0;
    for(int i = 1; i*i<=l; i++)
    {
        if(l%i == 0)
        {
            sd = sd + i;
            if(l/i != i)
                sd = sd + (l/i);
        }
    }
    if(l != 1)
        sd = sd - l;
    return sd;
}

int main()
{
    int k;
    cin >> k;
    for(int i = 1; i < k; i++)
    {
        int l = suma_dzielnikow(i);
        if((suma_dzielnikow(l) == i) && (i < l))
        {
            cout << i << " i " << l << endl;
        }
    }
}
