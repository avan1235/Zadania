#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int stopnie;
    int n;
    cin >> stopnie;
    cin >> n;
    double suma = 0;
    double radiany =( stopnie * M_PI ) / 180.0f;
    for(int i = 0 ; i< n; i++)
    {
        suma = suma + sin((i+1)*radiany);
    }

    cout<<suma<<endl<<1/(sin(radiany/2))<<endl;

    if(suma> (1/(sin(radiany/2))))
        cout<<"wieksze";
    else{
        cout<<"nie";
    }

    /*
        for(double i = 3; i < 1000000000; i++ )
        {
            double pier = pow(i,(1/i));
            if(pier>(1+(pow((6/((i-1)*(i-2))),(1/3)))))
                {
                    cout<<i<<endl;
                    break;
                }
        }

    */

    return 0;
}
