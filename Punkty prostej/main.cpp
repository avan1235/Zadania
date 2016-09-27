#include <iostream>

using namespace std;

int maxi(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

int mini(int a, int b)
{
    if(a<=b)
        return a;
    else
        return b;
}

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

int main()
{
    while(1)
    {
        int xp = 300, yp = 300, xq = 200, yq = 200, xr, yr;

        cin >> xr >> yr;

        if((sgn(det(xp, yp, xq, yq, xr, yr))==0)&&(xr>=mini(xp,xq))&&(xr<=maxi(xp,xq))&&(yr>=mini(yp,yq))&&(yr<=maxi(yp,yq)))
            cout << "Tak" << endl;
        else
            cout << "Nie" << endl;
    }
    return 0;
}
