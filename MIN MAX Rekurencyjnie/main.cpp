#include <iostream>

using namespace std;

void minmax_(int *a, int i, int j, int &min_i, int &max_i)
{
    if(i==j)
    {
        min_i = i;
        max_i = i;
    }
    if(i+1 == j)
    {
        if(a[i] < a[j])
        {
            min_i = i;
            max_i = j;
        }
        else
        {
            min_i = j;
            max_i = i;
        }
    }
    if(j-i > 1)
    {
        int k = (i+j) / 2;
        int min1, min2, max1, max2;
        minmax_(a, i, k, min1, max1);
        minmax_(a, k+1, j, min2, max2);
        if(a[min1]<a[min2])
            min_i = min1;
        else
            min_i = min2;
        if(a[max1] > a[max2])
            max_i = max1;
        else
            max_i = max2;
    }
}

int main()
{
    int n;
    cin >> n;
    int tab[n];
    while(n>0)
    {
        cin>>tab[n-1];
        n--;
    }
    int i = 0;
    int j = 9;
    int minimum = i;
    int maximum = j;
    minmax_(tab, i, j, minimum, maximum);
    cout<< "MIN: " << tab[minimum] << endl;
    cout<< "MAX: " << tab[maximum];


    return 0;
}
