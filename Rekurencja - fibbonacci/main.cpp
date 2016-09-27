#include <iostream>

using namespace std;

int i = 0;

int fib(int i)
{
    if( i == 1 || i == 2)
        return 1;
    else
        return fib(i-1) + fib(i-2);
}

int main()
{
    int k;
    cin >> k;
    cout << fib(k);
    return 0;
}
