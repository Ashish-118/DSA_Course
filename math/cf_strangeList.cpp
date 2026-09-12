#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int minDivideLvl = INT_MAX;
    int idx = -1;

    for (int i = 0; i < n; i++)
    {
        int q = a[i];
        int dvdLvl = 0;
        while (q % x == 0)
        {
            dvdLvl++;
            q = q / x;
        }

        if (dvdLvl < minDivideLvl)
        {
            minDivideLvl = dvdLvl;
            idx = i;
        }
    }

    // cout<<minDivideLvl<<endl;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int q = a[i];
        sum += q;
        int p = 1;

        int allowedLvl = (i < idx ? minDivideLvl + 1 : minDivideLvl);

        int lvl = 0;
        while (lvl < allowedLvl && q % x == 0)
        {
            sum += (p * x * (q / x));
            p = p * x;
            q = q / x;
            lvl++;
        }
    }

    cout << sum << endl;
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