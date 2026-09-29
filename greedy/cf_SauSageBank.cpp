#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;

    cout << (1LL << (n - k + 1)) + (k - 1) * 2 << '\n';
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