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
        bool c = true;
        int index = -1;
        for (int i = 0; i < n; i++)
            cin >> v[i];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                if ((abs(v[i] - v[j])) % k == 0)
                {
                    c = false;
                    break;
                }
            }
            if (c)
            {
                index = i;
                break;
            }
            else
            {
                if (i != (n - 1))
                    c = true;
            }
        }
        if (c)
        {
            cout << "YES" << endl;
            cout << index + 1 << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}