#include <iostream>
#include <cmath>

using namespace std;

void binarny(int n, bool tab[], int indeks)
{
    if(n>0)
    {
        binarny(n/2, tab, indeks-1);
        tab[indeks] = n%2;
    }
}

int main()
{
    int n;
    cin >> n;

    int rozmiar = ceil((log10(n+1))/(log10(2)));
    bool tab[rozmiar];

    binarny(n, tab, rozmiar-1);

    for(int i = 0; i<rozmiar; i++)
    {
        cout<<tab[i];
    }

    return 0;
}
