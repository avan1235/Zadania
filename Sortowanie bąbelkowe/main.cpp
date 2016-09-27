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

    for(int i = 0; i < 20-1; i++)
    {
        int tem;
        for(int j = 0; j < 20-1; j++)
        {
            if(tab[j+1] < tab[j])
            {
                tem = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tem;
            }
        }
    }

    cout << endl;

    for(int i = 0; i< 20; i++)
    {
        cout << tab[i] << " ";
    }

    return 0;
}
