#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));
    int tab[20];

    for(int i = 0; i< 20; i++)
    {
        tab[i] = rand()%100;
        cout << tab[i] << " ";
    }

    for(int i = 0; i < 20; i++)
    {
        int k = i;

        for(int j = i+1; j < 20; j++)
        {
            if(tab[j] < tab[k])
                k = j;
        }
        int tem;
        tem = tab[k];
        tab[k] = tab[i];
        tab[i] = tem;
    }

    cout << endl;

    for(int i = 0; i< 20; i++)
    {
        cout << tab[i] << " ";
    }

    return 0;
}
