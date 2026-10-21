#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<int> prefix(n, 0);

    int oddCount = 0, evenCount = 0;

    for (int i = 0; i < n; i++)
    {
        int prev = (i > 0 ? prefix[i - 1] : 0);
        int x;
        cin >> x;
        if (x & 1)
        {
            oddCount++;
        }
        else
        {
            evenCount++;
        }

        prefix[i] = prev + x;

        if (i == 0)
        {
            cout << x << " ";
        }
        else
        {
            int totalTurns = n;
            int mashaTurns = (totalTurns + 1) / 2;
            int OlyaTurns = totalTurns - mashaTurns;

            int d = oddCount / 3;
            int r = oddCount % 3;

            cout << prefix[i] - (d + (r == 1)) << " ";
        }
    }

    cout << endl;
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