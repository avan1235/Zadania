#include <iostream>

using namespace std;

int main()
{
    int l;
    cin >> l;
    if(l==1 || l==2)
        cout<<"1";
    else
    {
        int j = 1;
        int d = 1;

        while(l>2)
        {
            int tem = j;
            j = d;
            d = d+tem;
            l--;
        }
        cout<<d;
    }
    return 0;
}
