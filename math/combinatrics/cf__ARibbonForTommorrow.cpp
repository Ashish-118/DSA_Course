#include <bits/stdc++.h>
#define mod 998244353
using namespace std;

int FACT[1000001];
int INVFACT[1000001];

int BinExp(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1)
        {
            res = (res * 1LL * a) % mod;
        }
        a = (a * 1LL * a) % mod;
        b >>= 1;
    }
    return res;
}

void compute()
{
    FACT[0] = 1;
    for (int i = 1; i <= 1000000; i++)
    {
        FACT[i] = (1LL * FACT[i - 1] * i) % mod;
    }

    INVFACT[1000000] = BinExp(FACT[1000000], mod - 2);
    for (int i = 999999; i >= 0; i--)
    {
        INVFACT[i] = (1LL * INVFACT[i + 1] * (i + 1)) % mod;
    }
}
int ncr(int n, int r)
{
    if (n < 0 || r < 0 || n < r)
        return 0;

    return (1LL * FACT[n] * INVFACT[r] % mod * INVFACT[n - r]) % mod;
}

int main()
{
    int t;
    cin >> t;
    compute();

    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> segments;

        int count = 1;

        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                count++;
            }
            else
            {

                segments.push_back(count);
                count = 1;
            }
        }
        segments.push_back(count);

        int s1 = 0, k1 = 0;
        for (int i = 0; i < segments.size(); i = i + 2)
        {
            s1 += segments[i];
            k1++;
        }

        int ans1 = ((s1 > 0) ? ncr(s1 - 1, k1 - 1) : 1);

        int s2 = 0, k2 = 0;
        for (int i = 1; i < segments.size(); i = i + 2)
        {
            s2 += segments[i];
            k2++;
        }
        int ans2 = ((s2 > 0) ? ncr(s2 - 1, k2 - 1) : 1);

        cout << (1LL * ans1 * ans2) % mod << endl;
    }
    return 0;
}