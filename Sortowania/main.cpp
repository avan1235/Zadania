#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int n;

void losuj(int tab[], int n)
{
    for(int i = 0; i<n; i++)
    {
        tab[i] = rand()%100;
    }
}

void wypisz(int tab[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

void sortuj_babelkowe(int tab[], int n)
{
    for(int i = 0; i < (n-1); i++)
    {
        int temp;
        for(int j = 0; j<(n-1); j++)
        {
            if(tab[j+1]<tab[j])
            {
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
}

void sortuj_zliczanie(int tab[], int n)
{
    int ilosci[100];

    for(int i = 0; i<100; i++)
    {
        ilosci[i] = 0;
    }

    for(int i = 0; i<n; i++)
    {
        ilosci[tab[i]]++;
    }

    int z = 0;

    for(int i = 0; i<100; i++)
    {
         for(int j = 0; j < ilosci[i]; j++)
         {
             tab[z] = i;
             z++;
         }
    }
}

void sortuj_wybieranie(int tab[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int k = i;

        for(int j = i+1; j < n; j++)
        {
            if(tab[j] < tab[k]) // TAB[k]!!!
            {
                  k = j;
            }
        }

        int temp = tab[k];
        tab[k] = tab[i];
        tab[i] = temp;
    }
}

void sortowanie_wstawianie(int tab[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int bufor = tab[i];
        int j;

        for(j = i-1; (j>=0) && tab[j] > bufor; j--)
        {
            tab[j+1] = tab[j];
        }
        tab[j+1] = bufor;
    }
}

int main()
{
    srand(time(NULL));

    cin >> n;
    int tab[n];

    losuj(tab, n);
    wypisz(tab, n);

    //sortowanie_wstawianie(tab, n);
    //sortuj_wybieranie(tab, n);
    sortuj_zliczanie(tab, n);
    //sortuj_babelkowe(tab, n);

    wypisz(tab, n);
}
