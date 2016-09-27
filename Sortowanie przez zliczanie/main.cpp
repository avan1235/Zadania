#include <iostream>

using namespace std;

int main()
{
    int n, d, g;
    cin >> n;
    int a[n];

    for (int i = 0; i<n; i++)
        cin >> a[i];

    int b[10];

    for(int i = 0; i<10; i++)
        b[i] = 0;

    for(int i=0; i<n; i++)
        b[a[i]]++;

    int z = 0;

    for(int i = 0; i< 10; i++)
        for(int j = 0; j<b[i]; j++)
        {
            a[z] = i;
            z++;
        }

    for(int i = 0; i < n; i++)
        cout<<a[i]<<", ";

    return 0;
}
