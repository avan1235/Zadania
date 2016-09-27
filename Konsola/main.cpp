#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

using namespace std;
char const znak=(char)254;

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void ruch(int x, int y)   // funkcja wyœwietla znak gracza ? we wskazanym miejscu okna
{
    gotoxy(x,y);
    cout<<znak;
}

void show(int x, int y)
{
    gotoxy(x,y);
    cout<<znak;
}

int main()
{

    char c;
    char kolor[]="color   ";
    srand(time(NULL));     // po s³owie color s¹ 3 spacje
    kolor[6]=rand()%8+48;         // wybieram kolor t³a z przedzia³u 0-8
    kolor[7]=rand()%6+65;         // wybieram kolor czcionki z przedzia³u A-F
    system(kolor); // Borland C++: textcolor(kolor_czcionki), textbackground(tlo), clrscr()
    int x=rand()%80;
    int y=rand()%25;
    int act_x = x;
    int act_y = y;

    int wynik = 0;
    int tab[10][2];
//    string wynik = atoi(wynik);

    for(int i = 0; i<10; i++)
    {
        tab[i][0] = rand()%80;
        tab[i][1] = rand()%25;
        gotoxy(tab[i][0], tab[i][1]);
        cout<<"a";
    }



    do
    {
        show(act_x, act_y);
        //Sleep(25);
        system("cls");
        show(act_x, act_y);
        for(int i = 0; i<10; i++)
        {

            gotoxy(tab[i][0], tab[i][1]);
            cout<<"a";
        }
        c=getch();				// pobierz znak
        if (c==0)  			// jeœli wprowadzoo znak dwu-kodowy i pierwszy kod == 0
        {
            c=getch();			// pobierz drugi kod tego znaku

            switch (c)
            {
            case 75:
                x--;
                if (x<1)  x=x+80;
                act_x = x;
                act_y = y;
                ruch(x,y);
                break;    // w lewo
            case 77:
                x++;
                if (x>80) x=x-80;
                act_x = x;
                act_y = y;
                ruch(x,y);
                break;    // w prawo
            case 72:
                y--;
                if (y<1)  y=y+25;
                act_x = x;
                act_y = y;
                ruch(x,y);
                break;    // w gore
            case 80:
                y++;
                if (y>25) y=y-25;
                act_x = x;
                act_y = y;
                ruch(x,y);
                break;    // w dol
            }
        }
        for(int i = 0; i<10; i++)
        {
            if((tab[i][0] == x) && (tab[i][1] == y))
            {
                char kolor[]="color   ";
                srand(time(NULL));     // po s³owie color s¹ 3 spacje
                kolor[6]=rand()%8+48;         // wybieram kolor t³a z przedzia³u 0-8
                kolor[7]=rand()%6+65;         // wybieram kolor czcionki z przedzia³u A-F
                system(kolor);

                gotoxy(tab[i][0], tab[i][1]);
                cout << "a";
                wynik++;
            }
        }
    }
    while (c!=(char)13);
    return 0;
}

