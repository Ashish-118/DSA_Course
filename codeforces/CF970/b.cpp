#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        string s;
        cin >> s;
        int i = 0;
        int count_one = 0;
        while (s[i] != '0' && i < n)
        {

            count_one++;
            i++;
        }
        int count_zero = count(s.begin(), s.end(), '0');

        int matrix = count_one - 1;
        if (n==3 && count_one == 3)
        {
         cout<<"NO"<<endl;
        }
        
        else if (n == 4 && count_one == 4)
        {
            cout << "Yes" << endl;
        }
        else if ((matrix - 2) * (matrix - 2) == count_zero)
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