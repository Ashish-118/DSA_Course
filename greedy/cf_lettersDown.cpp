#include <bits/stdc++.h>
using namespace std;

void solve(int tc)
{
    int n;
    string s;
    cin >> n >> s;
    vector<pair<int, int>> coll;
    for (int i = 0; i < n; i++)
    {
        int j = n - i - 1;
        int x = (int)s[i], y = (int)s[j];
        if (x > y)
            swap(x, y);
        coll.push_back({x, y});
    }
    int ans = 0;
    sort(coll.begin(), coll.end());
    auto [l, r] = coll[0];
    for (auto [ll, rr] : coll)
    {
        if (ll <= r)
            r = max(rr, r);
        else
        {
            ans += r - l;
            l = ll, r = rr;
        }
    }
    ans += r - l;
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve(i);
}