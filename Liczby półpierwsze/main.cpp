#include <iostream>

using namespace std;

bool czy_pierwsza(int liczba)
{
    if(liczba <= 1)
        return 0;
    else
        for(int i = 2; i*i <= liczba; i++)
            if(liczba%i == 0)
                return 0;
    return 1;
}

int main()
{
    int l = 1;
    cin >> l;

    int ilosc_dzielnikow = 0;
    int dzielnik;

    for(int i = 2; i*i <= l; i++)
    {
        if(l%i == 0)
        {
            ilosc_dzielnikow++;
            dzielnik = i;
        }
    }

    if((ilosc_dzielnikow == 1) && (czy_pierwsza(dzielnik) == 1) && (czy_pierwsza((l/dzielnik)) == 1))
        cout << "Tak, liczba " << l << " jest liczba polpierwsza";
    else
        cout << "Nie, liczba " << l << " nie jest liczba polpierwsza";



    return 0;
}
