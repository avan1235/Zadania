#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream wyjscie;
    wyjscie.open("wyniki_6_1.txt", ios::out);
    int k = 0;
    string tem;
    int dl;
    cin >> tem;
    dl = tem.length();
    while(k<26)
    {
        for(int j = 0; j < dl; j++)
        {
            if((tem[j]-65)>=(k%26))
            {
                tem[j] = ((tem[j]-65)-(k%26))+65;
            }
            else
            {
                tem[j] = ((tem[j]-65)+26-(k%26))+66;
            }
        }
        cout << tem << " k="<< k <<endl;
        k++;
    }

}

/* 6.1
int main()
{
    fstream wyjscie;
    wyjscie.open("wyniki_6_1.txt", ios::out);
    int k = 107;
    string tem;
    int dl;
    for(int i = 0; i < 100; i++)
    {
        cin >> tem;
        dl = tem.length();
        for(int j = 0; j < dl; j++)
        {
            tem[j] = ((tem[j]-65)+(k%26))%26+65;
        }
        wyjscie << tem << endl;
    }

}
*/

/*
int main()
{
    fstream wyjscie;
    wyjscie.open("wyniki_6_2.txt", ios::out);
    int k;
    string tem;
    int dl;
    for(int i = 0; i < 3000; i++)
    {
        cin >> tem >> k;
        dl = tem.length();
        for(int j = 0; j < dl; j++)
        {
            if((tem[j]-65)>=(k%26))
            {
                tem[j] = ((tem[j]-65)-(k%26))+65;
            }
            else
            {
                tem[j] = ((tem[j]-65)+26-(k%26))+65;
            }
        }
        wyjscie << tem << endl;
    }
}
*/
/*

int main()
{
    fstream wyjscie;
    wyjscie.open("wyniki_6_3.txt", ios::out);
    int k;
    string slowo1, slowo2;
    int dl1, dl2;
    for(int i = 0; i < 100; i++)
    {
        cin >> tem >> k;
        dl = tem.length();
        for(int j = 0; j < dl; j++)
        {
            if((tem[j]-65)>=(k%26))
            {
                tem[j] = ((tem[j]-65)-(k%26))+65;
            }
            else
            {
                tem[j] = ((tem[j]-65)+26-(k%26))+65;
            }
        }
        wyjscie << tem << endl;
    }
}

*/

