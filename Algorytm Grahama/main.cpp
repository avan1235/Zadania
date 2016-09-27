#include <iostream>
#include <vector>
#include <stack>
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

int OnRight(int xp, int yp, int xq, int yq, int xr, int yr)
{
    if (sgn(det(xp, yp, xq, yq, xr, yr)) == -1)
        return 1;
    else
        return 0;
}

int main()
{
    // deklaracja - vector<int> liczby;
    // dopisanie na koniec - liczby.resize(i,dana);
    // odwo³anie do elementu - liczby[i]<<" ";
    // iloœæ elementów - liczby.size();
    // pierwszy element - liczby.front();
    // ostatni element - liczby.back();

    // stack <int> stos - dodawanie tylko na poczatku albo koncu
    // stos.top() - odniesienie do poczatku
    // stos.push() - dodanie elementu do stosu
    // stos.pop() - zdjêcie elementu ze stosu
    // stos.empty() - czy stos jest pusty
    // stos.size() - liczba elementów na stosie

    vector < pair < int, int > > Points;
    stack < pair <int, int> > Figure;
    pair <int, int> Temp;
    char Ans;
    int x, y, n;
    cin >> n;

    for(int i = 0; i<n; i++)
    {
        cin >> x >> y;
        Points.push_back(make_pair(x, y));
    }

    Figure.push(Points.at(0));
    Figure.push(Points.at(1));
    Figure.push(Points.at(2));

    Temp = Figure.top();
    Figure.pop();

    for(int i = 3; i < Points.size(); i++)
    {
        while(OnRight(Figure.top().first, Figure.top().second, Temp.first, Temp.second, Points.at(i).first, Points.at(i).second) == 1)
        {
            Temp = Figure.top();
            Figure.pop();
        }
        Figure.push(Temp);
        Temp = Points.at(i);
    }
    Figure.push(Temp);

    while(!Figure.empty())
    {
        cout << endl << Figure.top().first << " " << Figure.top().second;
        Figure.pop();
    }
    return 0;
}
