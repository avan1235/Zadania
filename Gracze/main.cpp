#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    fstream gracz1;
    fstream gracz2;

    int wygrane_1 = 0;
    int wygrane_2 = 0;

    string pobrane_1;
    string pobrane_2;

    int pobrane_1_l;
    int pobrane_2_l;

    gracz1.open("gracz1.txt", ios::in);
    gracz2.open("gracz2.txt", ios::in);

    if((gracz1.good() == 1) && (gracz2.good() == 1))
    {
        while((!gracz1.eof()) && (!gracz2.eof()))
        {
            getline(gracz1, pobrane_1);
            getline(gracz2, pobrane_2);

            pobrane_1_l = atoi(pobrane_1.c_str());
            pobrane_2_l = atoi(pobrane_2.c_str());

            if(pobrane_1_l > pobrane_2_l)
                wygrane_1++;
            if(pobrane_2_l > pobrane_1_l)
                wygrane_2++;
        }

        gracz1.close();
        gracz2.close();

        if(wygrane_1 == wygrane_2)
            cout << "Remis";
        else if(wygrane_1 > wygrane_2)
            cout << "Wygral gracz 1";
        else
            cout << "Wygral gracz 2";
    }

    else
        cout << "Nie udalo sie otworzyc ktoregos z plikow. Zamykam program.";

    return 0;
}
