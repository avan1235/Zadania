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
    int a, b;
    cin >> a >> b;
    if((suma_dzielnikow(a) == b) && (suma_dzielnikow(b) == a) && (a != b))
        cout << "Zaprzyjaznione";
    else
        cout << "Niezaprzyjaznione";
}
