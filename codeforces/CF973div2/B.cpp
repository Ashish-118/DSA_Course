#include <bits/stdc++.h>
#define int long long
using namespace std;

void battle(vector<int> &v, int i, int j)
{
    v[max(i, j)] = v[max(i, j)] - v[min(i, j)];
    v[min(i, j)] = 0;
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

        if (n > 2)
        {
            for (int j = (n - 3); j >= 0; j--)
            {
                battle(v, j, (n - 2));
            }
        }
        battle(v, (n - 2), (n - 1));
        cout << v[n - 1] << endl;
    }
}