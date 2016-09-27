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

bool czy_bliznicze(int m, int n)
{
    if(((czy_pierwsza(m) == 1) && (czy_pierwsza(n) == 1) && (((m-n) == 2) || ((m-n) == -2))))
        return 1;
    return 0;

}

int main()
{
    int p, d;
    cin >> p;
    cin >> d;

    if(czy_bliznicze(p, d) == 1)
        cout << "Liczby " << p << " i " << d << " sa blizniacze.";
    else
        cout << "Liczby " << p << " i " << d << " nie sa blizniacze.";

    return 0;
}
