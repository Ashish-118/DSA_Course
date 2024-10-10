#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(vector<int> v, int n)
{
    int i = 0;
    int j = n - 1;

    while (v[i] == v[i + 1])
    {
        i++;
    }

    while (v[j] == v[j - 1])
    {
        j--;
    }

    if (j == 0)
    {
        return 0;
    }

    if (v[0] == v[n - 1])
    {
        return abs((i + 1) - (j - 1)) + 1;
    }
    else
    {
        if ((i + 1) == (n - j))
        {
            return n - (i + 1);
        }
        else
        {
            return n - max((i + 1), (n - j));
        }
    }
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        cout << solve(v, n) << endl;
    }

    return 0;
}