#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long int s, m;
        cin >> n >> s >> m;

        vector<bool> timeScale(m , true);

        for (int i = 0; i < n; i++)
        {
           long long int a, b;
            cin >> a >> b;

            for (int j = a; j<b; j++)
            {
                timeScale[j] = false;
            }
        }
        
       
        long long int count = 0;
        for (long long int i = 0; i < m ; i++)
        {
            if (timeScale[i])
            {
                count++;
            }
            else
            {
                count = 0;
            }

            if (count == s)
            {
                break;
            }
        }


        if (count == s)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    
    }

    return 0;
}