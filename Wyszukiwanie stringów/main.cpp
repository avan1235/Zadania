#include <iostream>
#include <string>

using namespace std;

int main()
{
    string wczytane;
    string szukaj;

    getline(cin, wczytane);
    getline(cin, szukaj);

    int ile = 0;

    int dl_w = wczytane.length();
    int dl_sz = szukaj.length();

    int miejsce_wystapienia = wczytane.find(szukaj);

    while ((dl_sz <= dl_w)&&(miejsce_wystapienia!=-1))
    {
        ile++;

        wczytane = wczytane.substr(miejsce_wystapienia+1);
        dl_w = wczytane.length();

        miejsce_wystapienia = wczytane.find(szukaj);
    }

    cout<<ile;

    return 0;
}
