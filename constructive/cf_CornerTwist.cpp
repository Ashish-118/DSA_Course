#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> a(n), b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            while (a[i][j] != b[i][j])
            {
                int d = (b[i][j] - a[i][j] + 3) % 3;

                a[i][j] = (a[i][j] - '0' + d) % 3 + '0';
                a[i][j + 1] = (a[i][j + 1] - '0' + 3 - d) % 3 + '0';
                a[i + 1][j] = (a[i + 1][j] - '0' + 3 - d) % 3 + '0';
                a[i + 1][j + 1] = (a[i + 1][j + 1] - '0' + d) % 3 + '0';
            }
        }
    }

    cout << (a == b ? "YES\n" : "NO\n");
}

int main()
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