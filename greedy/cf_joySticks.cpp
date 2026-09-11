#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int a1, a2;
    cin >> a1 >> a2;

    int steps = 0;
    while ((a1 > 0 && a2 > 0) && (a1 > 1 || a2 > 1))
    {
        if (a1 > a2)
        {
            a1 -= 2;
            a2++;
            steps++;
        }
        else
        {
            a2 -= 2;
            a1++;
            steps++;
        }
    }
    cout << steps << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}