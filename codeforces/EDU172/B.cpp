#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> m;
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            m[x]++;
        }
        int unique = 0;
        for (auto j : m)
        {
            if (j.second == 1)
                unique++;
        }
        int distinct = m.size() - unique;
        cout << distinct + ((unique % 2 == 0 ? unique / 2 : (unique / 2) + 1)) * 2 << endl;
    }

    return 0;
}