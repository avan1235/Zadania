#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <pair<int, int>> p;
    vector <pair<int, int>> e;

    int n, l, r;
    cin >> n;
    for(int i = 0; i< n; i++)
    {
        cin >> l >> r;
        p.push_back(make_pair(l,r));
    }

    sort(p.begin(), p.end());

    for(int i = 0; i<n; i++)
    {
        if(p.at(i).second<p.at(i+1).first)
        {
            e.push_back(make_pair(p.at(i).first, p.at(i).second));
        }
    }

    for(int i = 0; i<e.size(); i++)
    {
        cout << e.at(i).first << " " << e.at(i).second;
    }

    return 0;
}
