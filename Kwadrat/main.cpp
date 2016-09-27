#include <iostream>

using namespace std;

void kwadrat(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        kwadrat(i);
        cout << endl;
    }

    return 0;
}
