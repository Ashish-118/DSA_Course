#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    string s;
    cin >> s;

    int n = s.length();

    int prev = -1;

    int ans = 0;

    for (int i = 0; i < n - 3; i++)
    {

        if (s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'r')
        {
            ans += (i - prev) * (n - (i + 3));
            prev = i;
        }
    }

    cout << ans << endl;
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