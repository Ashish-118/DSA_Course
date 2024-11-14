#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        int totalElements = n * m;
        int to_remove = (r - 1) * m + c;
        cout << (n - r) * m + (totalElements - to_remove - (n - r)) << endl;
    }

    return 0;
}