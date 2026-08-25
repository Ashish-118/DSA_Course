#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int x, y, n;
    cin >> x >> y >> n;

    int temp = y;
    int minus = 1;

    n -= 2;

    bool check = true;
    unordered_set<int> s;
    vector<int> ans;
    ans.push_back(y);

    while (n--)
    {
        int nextprev = temp - minus;

        if (nextprev <= x)
        {
            check = false;
            break;
        }

        ans.push_back(nextprev);
        s.insert(minus);
        temp = nextprev;
        minus++;
    }

    if (check && s.find(temp - x) == s.end())
    {
        ans.push_back(x);

        reverse(begin(ans), end(ans));

        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "-1" << endl;
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