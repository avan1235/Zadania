#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
/*
void zmien(int *wskaz)
{
    *wskaz = *wskaz + 10;
} */

/*int main()
{

    int *wsk;
    wsk = new int;
    *wsk = 5;
    //cout << "Pod adresem " << wsk << " znajduje sie wartosc " << *wsk;
    zmien(wsk);
    cout << *wsk;
    delete wsk;
    return 0;
}*/
/*
int main()
{
    srand(time(NULL));
    time_t start = time(NULL);

    int* tab = new int [1000000];
    int *wsk;
    wsk = tab;

    for(int i = 0; i < 1000000; i++)
    {
        *wsk = 1;
        wsk++;
    }


    cout << time(NULL) - start;
} */
/*
struct element
{
    int liczba;
    element *wsk;
};

void na_stos(int d, element *&w)
{
    element *temp;
    temp = w;
    w = new element;
    w->liczba = d;
    w->wsk = temp;
}

void ze_stosu(int &d, element *&w)
{
    element *temp = w;
    d = w->liczba;
    w = w->wsk;
    delete temp;
}

int main()
{
    element *wierzcholek = NULL;
    int x;
    do
    {
        cin >> x;
        na_stos(x, wierzcholek);
        cout << "Czy jeszcze? (0/1)" << endl
             << "Odp: ";
        cin >> x;
    }while(x==1);

    while(wierzcholek != NULL)
    {
        ze_stosu(x, wierzcholek);
        cout << x <<", ";
    }
}
*/

struct element
{
    int liczba;
    element *wsk;
};
void do_kolejki(int d, element *&kk)
{
    element *temp=kk;
    kk = new element;
    kk->liczba = d;
    kk->wsk = NULL;
    if (temp != NULL) temp->wsk = kk;
}
void z_kolejki(int &d, element *&pk)
{
    element *temp=pk;
    d=pk->liczba;
    pk=pk->wsk;
    delete temp;
}

int main()
{
    element *poczatek = NULL, *koniec = NULL;
    int x;

    do
    {
        cin >> x;
        do_kolejki(x, koniec);
        if(poczatek == NULL) poczatek = koniec;
        cout << "Czy jeszcze? (0/1)" << endl
             << "Odp: ";
        cin >> x;
    }while(x==1);

    while(poczatek != NULL)
    {
        z_kolejki(x, poczatek);
        cout << x <<", ";
    }
}
