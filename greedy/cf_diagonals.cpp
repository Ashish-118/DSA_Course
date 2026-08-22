#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int totalDiag = (2 * n) - 1;
        vector<int> v;
        for (int i = 1; i <= totalDiag / 2; i++)
        {
            v.push_back(i);
            v.push_back(i);
        }
        v.push_back(n);
        sort(v.begin(), v.end());

        int usedDiag = 0;
        while (k > 0)
        {
            k -= v.back();
            v.pop_back();
            usedDiag++;
        }

        cout << usedDiag << endl;
    }
    return 0;
}