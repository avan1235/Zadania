#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cmath>

using namespace std;

void losuj(int tab[], int n)
{
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        tab[i] = rand()%100+1;
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

void scal(int tab[], int p, int q, int r)
{
    int tab_pom[(r-p)];
    int i = p,
        j = q + 1,
        k = 0;

    while(i <= q && j<=r)
    {
        if(tab[j] < tab[i])
        {
            tab_pom[k] = tab[j];
            j++;
        }
        else
        {
            tab_pom[k] = tab[i];
            i++;
        }
        k++;
    }

    if(i <= q)
    {
        while(i <= q)
        {
            tab_pom[k] = tab[i];
            i++;
            k++;
        }
    }
    else
    {
        while(j <= r)
        {
            tab_pom[k] = tab[j];
            j++;
            k++;
        }
    }

    for(int i = 0; i <= r-p; i++)
        tab[p+i] = tab_pom[i];
}


void sortowanie_przez_scalanie(int tab[], int p, int r)
{
    if(p < r)
    {
        int q = ceil(((p+r)/2));
        sortowanie_przez_scalanie(tab, p, q);
        sortowanie_przez_scalanie(tab, q+1, r);
        scal(tab, p, q, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int tab[n];

    losuj(tab, n);
    pokaz(tab, n);

    sortowanie_przez_scalanie(tab, 0, n-1);

    pokaz(tab, n);

    return 0;
}
