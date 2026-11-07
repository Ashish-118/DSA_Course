#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int k, n;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(begin(a), end(a), greater<int>());

    int need = k - 1;
    int j = n - need;
    vector<int> b;
    int m = j;
    for (int i = 0; i < m; i++)
    {
        b.push_back(a[i]);
        if (j < n)
        {
            b.push_back(a[j++]);
        }
    }

    int count = 0;
    // prefix sum

    vector<int> prefix(b.size());
    prefix[0] = b[0];
    for (int i = 1; i < b.size(); i++)
    {
        prefix[i] = prefix[i - 1] + b[i];
    }

    for (int i = 0; i < b.size(); i++)
    {
        int prefixSum = (i > 0) ? prefix[i - 1] : 0;
        if ((b[i] * i) >= prefixSum)
        {
            count++;
        }
    }

    if (count == k)
    {
        cout << "YES" << endl;
        for (int i = 0; i < b.size(); i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    else
    {

        cout << "NO" << endl;
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