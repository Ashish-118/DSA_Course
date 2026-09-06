#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;

    int Odd = 0;
    int Even_1 = 0;
    int Even_2 = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x % 2 == 1)
        {
            Odd++;
        }
        else if (x % 4 == 0)
        {
            Even_1++;
        }
        else
        {
            Even_2++;
        }
    }

    cout << max({Odd, Even_1, Even_2}) << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}