#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    // max correct is 4n
    vector<int> len(4, 0);

    for (auto i : s)
    {
        if (i == 'A')
            len[0]++;
        if (i == 'B')
            len[1]++;
        if (i == 'C')
            len[2]++;
        if (i == 'D')
            len[3]++;
    }

    int correct_ans = 0;
    for (auto i : len)
    {
        correct_ans += min(n, i);
    }

    cout << correct_ans << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}