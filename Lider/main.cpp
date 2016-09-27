#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int tab[n];
    for(int i = 0; i<n; i++)
    {
        cin >> tab[i];
    }
    int licznik  = 0;
    int lider = tab[0];
    for(int i = 1; i<n; i++)
    {
        if(licznik == 0)
            lider = tab[i];
        if(tab[i] == lider)
        {
            licznik++;
        }
        else
        {

            licznik--;
        }
    }
    cout<<lider;
    return 0;
}
