#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <fstream>
#include <sstream>

const int WYMIAR_X = 101;
const int WYMIAR_Y = 25;

using namespace std;

char const hero = (char)158;
char const border = (char)219;
char const pac = (char)207;
char const bonus = (char)219;

short maps[WYMIAR_X][WYMIAR_Y];
fstream mapa;
char key;
char ch;
bool koniec;

void gotoxy(int x, int y);
void show_hero(int x, int y, int old_X, int old_Y);
void show_map();
void change_color(int x, int y);
bool load_map();
bool check_bonus(int x, int y);
void random_bonuses();

bool pierwszy = 1;

class monster
{

public:


    int act_X = 0;
    int act_Y = 0;
    int old_X = -1;
    int old_Y = -1;

    void rand_postion()
    {
        while((act_X == 0) || (act_Y == 0))
        {
            int x = rand()%(WYMIAR_X-2) + 1;
            int y = rand()%(WYMIAR_Y-2) + 1;

            if(maps[x-1][y-1] == 0)
            {
                act_X = x;
                act_Y = y;
                maps[act_X-1][act_Y-1] = -1;
            }
        }
    }

    void show()
    {
        gotoxy(act_X, act_Y);
        cout << pac;

        if((maps[old_X-1][old_Y-1] == -1) || (maps[old_X-1][old_Y-1] == 0))
        {
            if((old_X != -1) && (old_Y != -1))
            {
                gotoxy(old_X, old_Y);
                cout << " ";
                maps[old_X-1][old_Y-1] = 0;
            }
        }
        else if(maps[old_X-1][old_Y-1] == -2)
        {
            gotoxy(old_X, old_Y);
            cout << bonus;
            maps[old_X-1][old_Y-1] = -2;
        }
    }

    void change_position()
    {
        srand(time(NULL));
        int direction;
        bool changed = 1;

        while(changed)
        {
            direction = rand()%4;

            switch(direction)
            {
            case 0:
            {
                if(maps[act_X-1][act_Y-1-1] != 1)
                {
                    old_X = act_X;
                    old_Y = act_Y;
                    act_Y--;
                    changed = 0;
                }

            }
            break;
            case 1:
            {
                if(maps[act_X-1+1][act_Y-1] != 1)
                {
                    old_X = act_X;
                    old_Y = act_Y;
                    act_X++;
                    changed = 0;
                }
            }
            break;
            case 2:
            {
                if(maps[act_X-1][act_Y-1+1] != 1)
                {
                    old_X = act_X;
                    old_Y = act_Y;
                    act_Y++;
                    changed = 0;
                }
            }
            break;
            case 3:
            {
                if(maps[act_X-1-1][act_Y-1] != 1)
                {
                    old_X = act_X;
                    old_Y = act_Y;
                    act_X--;
                    changed = 0;
                }
            }
            break;
            }
        }
        maps[act_X-1][act_Y-1] = -1;
        maps[old_X-1][old_Y-1] = 0;
    }
};

monster pac1;
monster pac2;
monster pac3;
monster pac4;
monster pac5;
monster pac6;
monster pac7;
monster pac8;
monster pac9;
monster pac10;

DWORD WINAPI Watek_1(LPVOID lpParam)
{
    if(load_map() == 1)
    {
        do
        {
            system("cls");
            system("COLOR 0A");
            cout << "########################################\n"
                 << "################  MENU  ################\n"
                 << "########################################\n"
                 << "##### 1. GRAJ  #########################\n"
                 << "##### 2. WYJDZ #########################\n"
                 << "########################################\n"
                 << "\n\nPreferowany rozmiar okna - 101x25"
                 << "\nPreferowany rozmiar czcionki - 10x18"
                 << "\n\nPamietaj, aby wylaczyc NumLock";

            ch = getch();

            if(ch == '1')
            {

                do
                {
                    system("cls");
                    system("COLOR 8A");

                    int act_x = 52;
                    int act_y = 1;
                    int old_x = 0;
                    int old_y = 0;

                    int points = 0;

                    stringstream wynik;
                    wynik << points;
                    string points_s = wynik.str();
                    string a_w = "Gra Labirynt            Zebrane bonusy: ";

                    string to_show = a_w + points_s;

                    SetConsoleTitle(to_show.c_str());

                    random_bonuses();
                    show_map();
                    show_hero(act_x, act_y, 1, 1);

                    gotoxy(WYMIAR_X/2+2, 1);

                    while((((act_x != 52) || (act_y != 25))) && (key != (char)27) && (!((maps[act_x-1][act_y-1] == -1) || ((act_x == pac1.old_X) && (act_y == pac1.old_Y)) || ((act_x == pac2.old_X) && (act_y == pac2.old_Y)) || ((act_x == pac3.old_X) && (act_y == pac3.old_Y)) || ((act_x == pac4.old_X) && (act_y == pac4.old_Y)) || ((act_x == pac5.old_X) && (act_y == pac5.old_Y)) || ((act_x == pac6.old_X) && (act_y == pac6.old_Y)) || ((act_x == pac7.old_X) && (act_y == pac7.old_Y)) || ((act_x == pac8.old_X) && (act_y == pac8.old_Y)) || ((act_x == pac9.old_X) && (act_y == pac9.old_Y)) || ((act_x == pac10.old_X) && (act_y == pac10.old_Y)))))
                    {
                        gotoxy(WYMIAR_X/2+2, 1);
                        key = getch();

                        if(key == 0)
                        {
                            key = getch();

                            switch(key)
                            {
                            case 75: // W lewo
                            {
                                if((maps[act_x - 1 - 1][act_y - 1] != 1) && (act_x > 1))
                                {
                                    old_x = act_x;
                                    old_y = act_y;
                                    act_x = act_x - 1;
                                }
                            }
                            break;
                            case 77: // W prawo
                            {
                                if((maps[act_x - 1 + 1][act_y - 1] != 1) && (act_x < WYMIAR_X))
                                {
                                    old_x = act_x;
                                    old_y = act_y;
                                    act_x = act_x + 1;
                                }
                                if(act_x > WYMIAR_X)
                                    act_x = act_x - WYMIAR_X;
                            }
                            break;
                            case 72: // W gore
                            {
                                if((maps[act_x - 1][act_y - 1 - 1] != 1) && (act_y > 1))
                                {
                                    old_x = act_x;
                                    old_y = act_y;
                                    act_y = act_y - 1;
                                }
                                if(act_y < 1)
                                    act_y = act_y + WYMIAR_Y;
                            }
                            break;
                            case 80: // W dol
                            {
                                if((maps[act_x - 1][act_y - 1 + 1] != 1) && (act_y < WYMIAR_Y))
                                {
                                    old_x = act_x;
                                    old_y = act_y;
                                    act_y = act_y + 1;
                                }
                                if(act_y > WYMIAR_Y)
                                    act_y = act_y - WYMIAR_Y;
                            }
                            break;
                            }
                        }

                        show_hero(act_x, act_y, old_x, old_y);

                        if(check_bonus(act_x, act_y))
                        {
                            show_map();
                            change_color(act_x, act_y);
                            points++;
                        }

                        wynik.str("");
                        wynik << points;
                        points_s = wynik.str();
                        to_show = a_w + points_s;

                        SetConsoleTitle(to_show.c_str());
                    }


                    gotoxy(1, 1);
                    system("cls");
                    system("COLOR 0A");
                    cout << "####################################################################################"
                         << "\n################################# KONIEC ROZGRYWKI #################################"
                         << "\n####################################################################################"
                         << "\n############ Zdobyte bonusy: " << points;
                    gotoxy(73, 4);
                    cout << "############"
                         << "\n####################################################################################";

                    maps[act_x-1][act_y-1] = 0;

                    Sleep(3000);

                    if(((act_x == 52) && (act_y == 25)))
                        koniec = 0;
                }
                while((koniec) && (key != (char)27));
            }

        }
        while((ch != '2') && (key != (char)27));

    }
    else
    {
        cout << "Wystapil blad podczas wczytywania mapy. Zamykam program...";
        Sleep(5000);
    }

    return 0;
}

DWORD WINAPI Watek_2(LPVOID lpParam)
{
    while(1)
    {
        if(ch == '1')
        {
            if(pierwszy)
            {
                pac1.rand_postion();
                pac2.rand_postion();
                pac3.rand_postion();
                pac4.rand_postion();
                pac5.rand_postion();
                pac6.rand_postion();
                pac7.rand_postion();
                pac8.rand_postion();
                pac9.rand_postion();
                pac10.rand_postion();
                pierwszy = 0;
                Sleep(1000);
            }

            pac1.change_position();
            pac2.change_position();
            pac3.change_position();
            pac4.change_position();
            pac5.change_position();
            pac6.change_position();
            pac7.change_position();
            pac8.change_position();
            pac9.change_position();
            pac10.change_position();

            Sleep(250);

            pac1.show();
            pac2.show();
            pac3.show();
            pac4.show();
            pac5.show();
            pac6.show();
            pac7.show();
            pac8.show();
            pac9.show();
            pac10.show();

            Sleep(50);
        }
    }
}

int main()
{


    DWORD ThreadID1, ThreadParameter1 = 1;
    CreateThread(NULL, 0, Watek_1, &ThreadParameter1, 0, &ThreadID1);

    DWORD ThreadID2, ThreadParameter2 = 1;
    CreateThread(NULL, 0, Watek_2, &ThreadParameter2, 0, &ThreadID2);

    while(1);
}

void gotoxy(int x, int y)
{
    COORD cord;
    cord.X = x - 1;
    cord.Y = y - 1;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), cord);
}

void show_hero(int x, int y, int old_X, int old_Y)
{
    gotoxy(x, y);
    cout << hero;
    if(maps[old_X-1][old_Y-1] == 0)
    {
        gotoxy(old_X, old_Y);
        cout << " ";
    }
    else if(maps[old_X-1][old_Y-1] == -1)
    {
        gotoxy(old_X, old_Y);
        cout << pac;
    }
    else if(maps[old_X-1][old_Y-1] == -2)
    {
        gotoxy(old_X, old_Y);
        cout << bonus;
    }
}

void show_map()
{
    for(int i = 0; i < WYMIAR_Y; i++)
    {
        for(int j = 0; j < WYMIAR_X; j++)
        {
            gotoxy(j+1, i+1);

            if(maps[j][i] == 1)
                cout << border;
            else if(maps[j][i] == 2)
                cout << " ";
        }
    }
}

void change_color(int x, int y)
{
    char color[] = "COLOR   ";

    srand(time(NULL));
    color[6] = rand()%10 +48;
    color[7] = rand()%6 + 65;

    system(color);

    maps[x-1][y-1] = -2;
}

bool load_map()
{
    srand(time(NULL));
    char mapka[] = "map0.txt";
    mapka[3] = rand()%10 + 48;
    mapa.open(mapka, ios::in);

    string linia;
    if(mapa.good() == 1)
    {

        for(int i = 0; i < WYMIAR_Y; i++)
        {
            getline(mapa, linia);

            for(int j = 0; j < WYMIAR_X; j++)
            {
                if(linia[j] == '0')
                    maps[j][i] = 0;
                else
                    maps[j][i] = 1;
            }
        }
        return 1;
    }
    else
        return 0;
}

bool check_bonus(int x, int y)
{
    if(maps[x-1][y-1] == 2)
        return 1;
    return 0;
}

void random_bonuses()
{
    srand(time(NULL));

    for(int i = 0; i < WYMIAR_Y; i++)
    {
        for(int j = 0; j < WYMIAR_X; j++)
        {
            if(maps[j][i] == 0)
            {
                int random = rand()% (WYMIAR_X * WYMIAR_Y / 100);

                if(random == 0)
                    maps[j][i] = 2;
            }
        }
    }
}
