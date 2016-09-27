#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int w, n, l=0, aw=0;
    cin >> w >> n;
    int u[n];

    for(int i = 0; i< n; i++)
        cin >> u[i];

    sort(u, u+n);

    int mini = 0;
    int maxi = n-1;

    while (mini <= maxi)
    {
        if(u[mini]+u[maxi] > w)
        {
            maxi--;
            l++;
        }
        else
        {
            mini++;
            maxi--;
            l++;
        }
    }

    cout << l;
}
