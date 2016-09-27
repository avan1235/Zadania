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

int lustrzana(int temp)
{
    int lustrzana_liczba = 0;
    while(temp)
    {
        lustrzana_liczba = 10 * lustrzana_liczba + temp % 10;
        temp /= 10;
    }
    return lustrzana_liczba;
}

int main()
{
    int l;
    cin >> l;
    int l_l = lustrzana(l);

    if(czy_pierwsza(l) && czy_pierwsza(l_l))
    {
        cout << "Liczby " << l << " i " << l_l << " sa liczbami lustrzanymi pierwszymi.";
    }
    else
    {
        cout << "Liczby " << l << " i " << l_l << " nie sa liczbami lustrzanymi pierwszymi.";
    }

    return 0;
}
