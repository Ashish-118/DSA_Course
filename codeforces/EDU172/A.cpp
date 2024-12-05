#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end(), greater<>());
        int add = 0;

        for (int i = 0; i < n; i++)
        {
            if ((add + v[i]) > k)
                break;
            else
                add += v[i];
        }

        cout << (k - add) << endl;
    }

    return 0;
}