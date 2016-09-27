#include <iostream>
#include <cmath>

using namespace std;

void binarny(int l, int j, char tab[], int indeks)
{
    if(l > 0)
    {
        binarny(l/j, j, tab, indeks-1);
        int p = l%j;

        if(p >= 0 && p <= 9)
            tab[indeks] = p+48;
        else
            tab[indeks] = p+55;
    }
}

int main()
{
    int l, j;
    cin >> l >> j;

    int rozmiar = ceil((log10(l+1))/(log10(j)));
    char tab[rozmiar];

    binarny(l, j, tab, rozmiar-1);

    for(int i = 0; i<rozmiar; i++)
    {
        cout<<tab[i];
    }

    return 0;
}
