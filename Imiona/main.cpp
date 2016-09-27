#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream imiona;
    fstream panie;
    fstream panowie;
    imiona.open("imiona.txt", ios::in);
    panie.open("panie.txt", ios::out);
    panowie.open("panowie.txt", ios::out);

    if((imiona.good() == 1) && (panie.good() == 1) && (panowie.good() == 1))
    {
        string imie;
        int dlugosc;

        int ile_panow = 0;
        int ile_pan = 0;

        while(!imiona.eof())
        {
            getline(imiona, imie);
            dlugosc = imie.length();

            if(imie[dlugosc-1]=='a')
            {
                panie << imie << endl;
                ile_pan++;
            }

            else
            {
                panowie << imie << endl;
                ile_panow++;
            }
        }

        panie << ile_pan;
        panowie << ile_panow;

        imiona.close();
        panie.close();
        panowie.close();

        cout << "Zakonczono pomyslnie";
    }
    else
        cout << "Nie udalo sie otworzyc ktoregos z plikow. Zamykam program.";



    return 0;
}
