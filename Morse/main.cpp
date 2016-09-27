#include <iostream>

using namespace std;

int main()
{
    while(1)
    {
        string s;
        getline(cin, s);

        int d = s.length();

        cout << "1 ";

        for(int i = 0; i < d; i++)
        {
            if(s[i] == '.')
            {
                cout << "1 ";

                if(s[i+1] == '.' || s[i+1] == '-')

                    cout << "1 ";

                else if(s[i+1] == ' ')

                    cout << "3 ";
            }
            else if(s[i] == '-')
            {

                cout << "3 ";

                if(s[i+1] == '.' || s[i+1] == '-')

                    cout << "1 ";

                else if(s[i+1] == ' ')

                    cout << "3 ";
            }
        }
    }
    return 0;
}
