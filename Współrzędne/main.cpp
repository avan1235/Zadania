#include <iostream>
#include <windows.h>
#include <cstdlib>
#define DELAY 5
using namespace std;

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void kwadrat_przekatne(int n)
{
    for (int i = 0; i < n; i++)
    {
        gotoxy(1, i+1);
        cout<<"*";
        gotoxy(n, i+1);
        cout<<"*";
    }
    for (int i = 0; i < n; i++)
    {
        gotoxy(i+1, 1);
        cout<<"*";
        gotoxy(i+1, n);
        cout<<"*";
    }
    for(int i = 1; i<=n; i++)
    {
        gotoxy(i, i);
        cout<<"*";
    }
    for(int i = 0; i < n; i++)
    {
        gotoxy(n-i, i+1);
        cout<<"*";
    }
}

void slimak(int n)
{
    system( "cls" );
    for(int i = 0; i < n; i++)
    {
        for(int  j = i+1 ; j < n-i+1; j++)
        {
            gotoxy( j , i+1 );
            cout<< "*";
            Sleep(DELAY);
        }
        for(int  j = i+1 ; j < n-i+1; j++)
        {
            gotoxy( n-i+1 , j );
            cout<< "*";
            Sleep(DELAY);
        }
        for(int  j = i+1 ; j < n-i+1; j++)
        {
            gotoxy( n-j+1 , n-i );
            cout<< "*";
            Sleep(DELAY);
        }
        for(int  j = i+1 ; j < n-i+1; j++)
        {
            gotoxy( i+1 , n-j );
            cout<< "*";
            Sleep(DELAY);
        }

    }
}

int main()
{
    int n;
    cin >> n;
    while(1)
    {
        slimak(n);
        system("cls");
    }
    gotoxy(n, n);
    return 0;
}
