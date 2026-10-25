#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> degree(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        degree[x]++;
        degree[y]++;
    }

    sort(degree.begin() + 1, degree.end());

    if (degree[1] == 0)
    {
        cout << "Brain Melt\n";
    }
    else if (degree[n] == n - 1 && degree[n - 1] == 1)
    {
        cout << "2\n";
    }
    else
    {
        cout << "Many\n";
    }
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