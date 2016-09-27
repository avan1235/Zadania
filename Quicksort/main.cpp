#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

void losuj(int tab[], int n)
{
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        tab[i] = rand()%25+1;
    }
}

void pokaz(int tab[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

void quick_sort(int *tab, int lewy, int prawy)
{
    int piwot = tab[((lewy+prawy)/2)];
    int i = lewy;
    int j = prawy;
    int temp;

    do
    {
        while(tab[i] < piwot)
            i++;
        while(tab[j] > piwot)
            j--;

        if(i <= j)
        {
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            i++;
            j--;
        }
    }while(i <= j);

    if(j > lewy)
        quick_sort(tab, lewy, j);
    if(i < prawy)
        quick_sort(tab, i, prawy);
}

int main()
{
    int n;
    cin >> n;
    int tab[n];

    losuj(tab, n);
    pokaz(tab, n);
    quick_sort(tab, 0, n-1);
    pokaz(tab, n);

    return 0;
}

