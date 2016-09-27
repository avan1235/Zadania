#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "cstdlib"

using namespace std;

int main()
{
    fstream Input1;
    fstream Input2;
    fstream Output;

    int LengthOne = 0;
    int LengthTwo = 0;

    Input1.open("ciag1.txt", ios::in);
    Input2.open("ciag2.txt", ios::in);
    Output.open("wynik.txt", ios::out);

    if (Input1.good() && Input2.good() && Output.good())
    {
        string Bufor;
        string ToFile;

        while(!(Input1.eof()))
        {
            getline(Input1, Bufor);
            LengthOne++;
        }

        while(!(Input2.eof()))
        {
            getline(Input2, Bufor);
            LengthTwo++;
        }

        Input1.close();
        Input2.close();

        int TabOne[LengthOne];
        int TabTwo[LengthTwo];
        int TabFinal[(LengthOne + LengthTwo)];

        Input1.open("ciag1.txt", ios::in);
        Input2.open("ciag2.txt", ios::in);

        int i = 0;

        while(!(Input1.eof()))
        {
            getline(Input1, Bufor);
            TabOne[i] = atoi(Bufor.c_str());
            i++;
        }

        i = 0;

        while(!(Input2.eof()))
        {
            getline(Input2, Bufor);
            TabTwo[i] = atoi(Bufor.c_str());
            i++;
        }

        int i1 = 0,
            i2 = 0;
        i = 0;

        while( i < (LengthOne + LengthTwo))
        {
            if((i1 < LengthOne) && (i2 < LengthTwo))
            {
                if(TabOne[i1] <= TabTwo[i2])
                {
                    TabFinal[i] = TabOne[i1];
                    i1++;
                }
                else
                {
                    TabFinal[i] = TabTwo[i2];
                    i2++;
                }
            }
            else
            {
                if(i1 < LengthOne)
                {
                    TabFinal[i] = TabOne[i1];
                    i1++;
                }

                if(i2 < LengthTwo)
                {
                    TabFinal[i] = TabTwo[i2];
                    i2++;
                }
            }
            i++;
        }

        for(int i = 0; i < (LengthOne + LengthTwo); i++)
        {
            ostringstream Write;
            Write << TabFinal[i];
            ToFile = Write.str();
            Output << ToFile << endl;
        }

        Input1.close();
        Input2.close();
        Output.close();

        cout << "Zakonczono pomyslnie.";
    }
    else
    {
        cout << "Blad w plikach.";
    }

    return 0;
}
