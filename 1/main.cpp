#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++)
    {
        for(int j=0;j<(n+i);j++)
        {
            cout << "* ";
        }
        cout<<endl;
    }
    return 0;
}
