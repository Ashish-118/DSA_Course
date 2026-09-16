#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    priority_queue<int> pq;
    int sum = 0;
    for (int i = 0; i < m - 1; i++)
    {
        pq.push(v[i]);
        sum += v[i];
    }

    int ans = LLONG_MIN;

    for (int i = m - 1; i < n; i++)
    {
        ans = max(ans, m * v[i] - sum);

        if (!pq.empty() && pq.top() > v[i])
        {
            sum -= pq.top();
            pq.pop();
            pq.push(v[i]);
            sum += v[i];
        }
    }

    cout << ans << endl;
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