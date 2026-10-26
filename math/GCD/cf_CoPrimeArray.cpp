#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<int> a;
    int prev = 1;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (gcd(prev, x) != 1)
        {
            k++;
            a.push_back(1);
            a.push_back(x);
        }
        else
        {
            a.push_back(x);
        }
        prev = x;
    }
    cout << k << endl;

    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}