#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int sgn(int a)
{
    if(a>0)
        return 1;
    else if (a==0)
        return 0;
    else
        return -1;
}

int det (int xp, int yp, int xq, int yq, int xr, int yr)
{
    return xp*(yq-yr)+yp*(xr-xq)+(xq*yr-yq*xr);
}

int Where(int xp, int yp, int xq, int yq, int xr, int yr)
{
    if (sgn(det(xp, yp, xq, yq, xr, yr)) == -1)
        return 1;
    else if (sgn(det(xp, yp, xq, yq, xr, yr)) == 0)
        return -1;
    else
        return 0;
}

int main()
{
    int n, ActX, ActY, Index = 0;
    bool ending = 1;
    cin >> n;
    vector<pair<int,int> > Points(n);
    vector<pair<int,int> > Figure(n);

    for(int i = 0; i<n; i++)
    {
        cin >> ActX >> ActY;
        Points.at(i).first = ActX;
        Points.at(i).second = ActY;
    }

    Figure.at(0) = Points.at(0);

    for(int i = 0; i<n; i++)
        if(Points.at(i).second <= Figure.at(0).second)
            Figure.at(0) = Points.at(i);

    for(int i = 0; i<n && ending == 1; i++)
    {
        ActX = Points.at(i).first;
        ActY = Points.at(i).second;

        for(int  j = 0; j < n; j++)
        {
            // Punkt po prawej
            if((Where(Figure.at(Index).first, Figure.at(Index).second, ActX, ActY, Points.at(j).first, Points.at(j).second)) == 1)
            {
                ActX = Points.at(j).first;
                ActY = Points.at(j).second;
            }
            // Przypadek punktów wspó³liniowych
            else if(((Where(Figure.at(Index).first, Figure.at(Index).second, ActX, ActY, Points.at(j).first, Points.at(j).second)) == -1) && Index > 0 )
            {
                int Way1 = (Figure.at(Index).first - ActX)*(Figure.at(Index).first - ActX) + (Figure.at(Index).second - ActY)*(Figure.at(Index).second - ActY);
                int Way2 = (Figure.at(Index).first - Points.at(j).first)*(Figure.at(Index).first - Points.at(j).first) + (Figure.at(Index).second - Points.at(j).second)*(Figure.at(Index).second - Points.at(j).second);

                if(Way1 < Way2)
                {
                    ActX = Points.at(j).first;
                    ActY = Points.at(j).second;
                }
            }
        }

        if ((Index > 0) && (ActX==Figure.at(0).first) && (ActY==Figure.at(0).second))
            ending = 0;

        Index++;
        Figure.at(Index).first = ActX;
        Figure.at(Index).second = ActY;
    }

    // Wypisanie punktów

    system("cls");

    for(int i = 0; i<Index; i++)
        cout << "Dodano " << i+1 << " punkt: " << Figure.at(i).first << " " << Figure.at(i).second << endl;

    cout << endl;
    system("PAUSE");
}

