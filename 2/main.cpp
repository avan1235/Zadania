#include <iostream>
#include <fstream>
using namespace std;



int main()
{
    fstream plik;
    plik.open("fibo_data.txt", ios::out);
    if(plik.good())
    {
        int ile;
        cin >> ile;
        int tab[ile];
        int i = 1;
        int j = 1;
        int tem;
        if(ile == 1)
            tab[0] = 1;
        else if(ile == 2)
        {
            tab[0] = 1;
            tab[1] = 1;
        }
        else
        {
            tab[0] = 1;
            tab[1] = 1;
            for(int k = 2; k<ile; k++)
            {
                tem = i;
                i=i+j;
                j=tem;
                tab[k] = i;

            }
        }

        for(int m = 0; m<ile; m++)
        {
            plik<<tab[m]<<"\t";
        }
    }
    else
        cout << "Blad";
    return 0;
}
