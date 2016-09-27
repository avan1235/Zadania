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



    for(int i = 1; i < 20; i++)
    {
        int j = i;
        int buf = tab[j];
        while((j > 0) && (tab[j - 1] > buf))
        {
            tab[j] = tab[j-1];
            j--;
        }
        tab[j] = buf;
    }

    cout << endl;

    for(int i = 0; i< 20; i++)
    {
        cout << tab[i] << " ";
    }

    return 0;
}
