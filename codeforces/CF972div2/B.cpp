#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        int t1, t2;
        cin >> t1 >> t2;
        int q1;
        cin >> q1;
        cout << min(abs(q1-t1),abs(q1-t2))<<endl;
    }
    return 0;
}