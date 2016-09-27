#include <iostream>

using namespace std;

int suma_cyfr(int l)
{
    int s = 0;

    while (l >= 1)
    {
        s = s + (l%10);
        l = (l - (l%10))/10;
    }

    return s;
}

int main()
{
    int liczba, cyfra;

    cin >> liczba;

    cyfra = liczba;

    while (cyfra > 9)
        cyfra = suma_cyfr(cyfra);

    cout << "Liczba " << liczba << " jest podobna do cyfry " << cyfra;

    return 0;
}
