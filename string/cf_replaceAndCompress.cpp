#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    string s;
    cin >> s;

    int n = s.length();
    int ans = 1;

    int zeroes = 0;
    int ones = 0;
    bool used = false;
    bool singleBit = false;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {

            if (ones >= 3)
            {
                ans += 1;
                used = true;
                break;
            }
            zeroes++;
            ones = 0;
        }
        else
        {

            if (zeroes >= 3)
            {
                ans += 1;
                used = true;
                break;
            }
            ones++;
            zeroes = 0;
        }
    }

    if (!used)
    {

        if (zeroes >= 3)
        {
            ans += 1;
        }
        else if (ones >= 3)
        {
            ans += 1;
        }
    }

    ones = 0;
    zeroes = 0;

    int start = 1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            start++;
        }
        else
        {
            break;
        }
    }

    int end = n - 2;

    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == s[i + 1])
        {
            end--;
        }
        else
        {
            break;
        }
    }

    used = false;

    for (int i = start; i <= end; i++)
    {
        if (s[i] == '0')
        {

            if (ones == 1)
            {
                ans += 1;
                used = true;
                break;
            }
            zeroes++;
            ones = 0;
        }
        else
        {

            if (zeroes == 1)
            {
                ans += 1;
                used = true;
                break;
            }
            ones++;
            zeroes = 0;
        }
    }

    if (!used)
    {
        if (ones == 1 || zeroes == 1)
        {
            ans += 1;
        }
    }

    cout << ans << endl;
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