#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int ile, a, b; // ile liczb, dolna i gorna granica losowania
    cin >> ile >> a >> b;

    int tab[ile];

    srand(time(NULL));

    for(int i = 0; i < ile; i++)
        tab[i] = ((rand()%(b-a+1))+a);

    int max_wart = 0;
    int licznik = 1;

    for(int i = 0; i < (ile-1); i++)
    {
        for(int j = i; tab[j+1] >= tab[j]; j++ )
        {
            licznik++;
        }

        if(licznik > max_wart)
        {
            max_wart = licznik;
            i = i + max_wart;
        }

        licznik = 1;
    }
    /*
    for(int i = 0; i < ile; i++)
        cout << tab[i] << " ";
    cout << endl;
    */
    cout << max_wart;

    return 0;
}
