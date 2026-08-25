#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int x;
    cin >> x;

    int count = 0;

    int c1 = 0, c2 = 0, c3 = 0;

    while (c1 != x || c2 != x || c3 != x)
    {
        bool changed = false;

        for (int i = 1; i <= 3; i++)
        {
            if (i == 1 && c1 != x)
            {

                int mini = min(c3, c2);
                int diff = 2 * mini - c1 + 1;
                c1 += min(x - c1, diff);
                count++;
                changed = true;
            }
            else if (i == 2 && c2 != x)
            {
                int mini = min(c1, c3);
                int diff = 2 * mini - c2 + 1;

                c2 += min(x - c2, diff);
                count++;
                changed = true;
            }
            else if (i == 3 && c3 != x)
            {
                int mini = min(c1, c2);
                int diff = 2 * mini - c3 + 1;

                c3 += min(x - c3, diff);
                count++;
                changed = true;
            }
            if (!changed)
                break;
        }
    }

    cout << count << endl;
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