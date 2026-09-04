#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> ans(n);

    int left = m;

    for (int i = 0; i < n; i++)
    {
        int names = a[i];
        int pagesTurn = 0;

        if (left <= a[i])
        {
            a[i] -= left;
            pagesTurn++;
            left = m;

            pagesTurn += a[i] / left;
            a[i] = a[i] % left;
        }

        if (a[i] < left)
        {
            left -= a[i];
        }

        ans[i] = pagesTurn;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}