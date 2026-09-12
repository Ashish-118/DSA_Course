#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    if ((a != 0 || b != 0) && (x == x1 && x1 == x2))
    {
        // cout << "hi1" << endl;
        cout << "NO" << endl;
        return;
    }
    if ((c != 0 || d != 0) && (y == y1 && y1 == y2))
    {
        // cout << "hi2" << endl;
        cout << "NO" << endl;
        return;
    }

    int left_moves = min(x - x1, a);
    a -= left_moves;
    int newX = x - left_moves;
    int right_poss_moves = x2 - newX;

    if (a != 0)
    {
        if (b < a)
        {
            // cout << "hi3" << endl;
            cout << "NO" << endl;
            return;
        }
        b -= a;
    }

    if (b > right_poss_moves)
    {
        // cout << "hi4" << endl;
        cout << "NO" << endl;
        return;
    }

    // now for vertical

    int up_moves = min(y2 - y, d);
    d -= up_moves;
    int newY = y + up_moves;
    int down_poss_moves = newY - y1;

    if (d != 0)
    {
        if (c < d)
        {
            // cout << "hi5" << endl;
            cout << "NO" << endl;
            return;
        }
        c -= d;
    }

    if (c > down_poss_moves)
    {
        // cout << "hi6" << endl;
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
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