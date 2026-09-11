#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    string num;
    cin >> num;

    int n = num.length();
    int i = n - 1;

    int carry = 0;
    int idx = -1;

    while (i >= 0)
    {
        if (carry)
        {
            if (num[i] == '9')
            {
                num[i] = '0';
                carry = 1;
            }
            else
            {
                num[i]++;
                carry = 0;
            }
        }

        if (num[i] >= '5')
        {
            idx = i;
            num[i] = '0';
            carry = 1;
        }

        i--;
    }

    string ans = "";

    if (carry)
    {
        ans += "1";
        ans += string(n, '0');
    }
    else
    {
        if (idx == -1)
        {
            ans = num;
        }
        else
        {
            ans += num.substr(0, idx);
            ans += string(n - idx, '0');
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