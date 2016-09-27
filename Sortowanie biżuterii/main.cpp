#include <iostream>

using namespace std;

void Sortowanie( int tab[], int left, int right);

int main()
{
    int ile;
    cin >> ile;

    string ciagi[ile];

    for(int i = 0; i<ile; i++)
    {
        cin>>ciagi[i];
    }

    int dl[ile];
    int pom[ile];

    for(int i = 0; i < ile; i++)
    {
        dl[i] = ciagi[i].length();
        pom[i] = dl[i];
    }

    Sortowanie(pom, 0, ile-1);

     for(int i = 0; i < ile; i++)
    {
        cout<<pom[i];
    }



    return 0;
}

void Sortowanie( int tab[], int left, int right )
{
    int i = left;
    int j = right;
    int x = tab[( left + right ) / 2 ];
    do
    {
        while( tab[ i ] < x )
             i++;

        while( tab[ j ] > x )
             j--;

        if( i <= j )
        {
            swap( tab[ i ], tab[ j ] );

            i++;
            j--;
        }
    } while( i <= j );

    if( left < j ) Sortowanie( tab, left, j );

    if( right > i ) Sortowanie( tab, i, right );
}
