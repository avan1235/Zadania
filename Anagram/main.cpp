#include <iostream>
#include <string>

using namespace std;

int main()
{
    string pierwsze_slowo;
    string drugie_slowo;

    getline(cin, pierwsze_slowo);
    getline(cin, drugie_slowo);

    int dl_p = pierwsze_slowo.length();
    int dl_d = drugie_slowo.length();

    int max_liter;

    int ilosc_jeden[26];
    int ilosc_dwa[26];

    /* Znalezienie dluzszego slowa tak aby
     * ustawic ilosc sprawdzanych znakow na ilosc znakow tego slowa
     * i spacje traktowac jako zera po zamianie na cyfry
     * gdyz w anagramach moze byc rozna ilosc spacji
     * a dalej beda to anagramy
     */

    if(dl_p >= dl_d)
        max_liter = dl_p;
    else
        max_liter = dl_d;

    int cyfry_jeden[max_liter];
    int cyfry_dwa[max_liter];

    for(int i = 0; i<max_liter; i++)
        cyfry_jeden[i] = 0;
    for(int i = 0; i<max_liter; i++)
        cyfry_dwa[i] = 0;

    for(int i = 0; i<26; i++)
        ilosc_jeden[i] = 0;
    for(int i = 0; i<26; i++)
        ilosc_dwa[i] = 0;

    bool blad = 1;

    /* Zamiana liter na cyfry poprze odejmowanie odpowiednich wartosci
     * i zapisanie ich do tablic cyfry_
     * oddzielnie dla duzycj i dla malych liter
     */

    for(int i = 0; i < dl_p; i++)
    {
        if((pierwsze_slowo[i]>=65) && (pierwsze_slowo[i]<=90))
            cyfry_jeden[i] = pierwsze_slowo[i] - 65;
        else if((pierwsze_slowo[i]>=97) && (pierwsze_slowo[i]<=122))
            cyfry_jeden[i] = pierwsze_slowo[i] - 97;
    }

    for(int i = 0; i < dl_d; i++)
    {
        if((drugie_slowo[i]>=65) && (drugie_slowo[i]<=90))
            cyfry_dwa[i] = drugie_slowo[i] - 65;
        else if((drugie_slowo[i]>=97) && (drugie_slowo[i]<=122))
            cyfry_dwa[i] = drugie_slowo[i] - 97;
    }

    /* Zliczanie wystepowania poszczegolnych liczb
     * (a wiec odpowiadajacych im liter)
     */

    for(int i = 0; i < max_liter; i++)
        ilosc_jeden[cyfry_jeden[i]]++;

    for(int i = 0; i < max_liter; i++)
        ilosc_dwa[cyfry_dwa[i]]++;

    /* Porownanie ilosci wystapien poszczegolnych liczb
     * (a wiec odpowiadajacych im liter)
     */

    for(int i = 0; ((i < 26) && (blad == 1)); i++)
        if(ilosc_jeden[i] != ilosc_dwa[i])
            blad = 0;

    if(blad == 1)
        cout << "Anagram";
    else
        cout << "Nie anagram";

    return 0;
}
