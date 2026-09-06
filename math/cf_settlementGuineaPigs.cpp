#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int m = -1, f = -1, countU = 0, bought = 0, freeU = 0;

    for (int i = 0; i < n; i++)
    {

        if (b[i] == 1)
        {
            if (m == -1)
            {
                m = 1;
                bought++;
            }
            else if (f == -1)
            {
                f = 1;
                bought++;
            }
            else if (freeU)
            {
                freeU--;
                countU++;
            }
            else
            {
                bought++;
                countU++;
            }
        }
        else
        {
            while (countU > 0)
            {
                countU--;
                if (m == 1 && f == 1)
                {
                    m++;
                    freeU++;
                }
                else
                {
                    if (m == 2)
                    {
                        m = 1;
                    }
                }
            }
        }

        // cout<<bought<<" ";
    }
    // cout<<endl;

    cout << bought << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}