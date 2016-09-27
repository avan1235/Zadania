#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n, x1, x2, y1, y2;

    cout << "n = ";
    cin >> n;
    cout << "x1 = ";
    cin >> x1;
    cout << "y1 = ";
    cin >> y1;
    cout << "x2 = ";
    cin >> x2;
    cout << "y2 = ";
    cin >> y2;


    vector<int> w(n);
    vector<vector<int> > tab(n,w);

    for(int i = 0; i < n; i++)
    {
        if(i%2 == 0)
        {
            for(int j = 0; j< n; j++)
            {
                if(j%2 == 0)
                    tab[j][i] = 1;
                else
                    tab[j][i] = 0;
            }
        }
        else
        {
            for(int j = 0; j< n; j++)
            {
                if(j%2 == 0)
                    tab[j][i] = 0;
                else
                    tab[j][i] = 1;
            }
        }
    }

    // Krolowe to 2
    tab[x1-1][y1-1] = 2;
    tab[x2-1][y2-1] = 2;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            if(tab[j][i] != 2)
                cout << tab[j][i];
            else
                cout << "K";
        cout<<endl;
    }

    if((x1 == x2) || (y1 == y2) || (abs(x1-x2) == abs(y1-y2)))
        cout << "TAK";
    else
        cout << "NIE";

    return 0;
}
