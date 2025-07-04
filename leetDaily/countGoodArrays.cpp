// this code is a partially correct solution for the problem -- count the num of arrays with k matching adjacent elements

// #include <bits/stdc++.h>

// #define mod 1000000007

// int add(int a, int b)
// {
//     return (a % mod + b % mod) % mod;
// }

// int mul(int a, int b)
// {
//     return ((a % mod) * 1LL * (b % mod)) % mod;
// }

// class Solution
// {
// public:
//     int countGoodArrays(int n, int m, int k)
//     {
//         int x = 1;

//         for (int i = 0; i < (n - (k + 1)); i++)
//         {
//             x = mul(x, m - 1);
//         }
//         int f = mul(m, x);
//         if (m == 1)
//         {
//             if (k != 0)
//                 return k;
//         }
//         cout << f << endl;
//         if (k == 0)
//             return f;
//         else if (k == 1)
//             return 2 * f;
//         else if ((n - (2 * k)) == 0)
//             return 3 * f;
//         else
//             return 4 * f;
//     }
// };

/// corrected solutions

const int MOD = 1e9 + 7;
const int MX = 1e5;

long long fact[MX];
long long inv_fact[MX];

class Solution
{
    long long qpow(long long x, int n)
    {
        long long res = 1;
        while (n)
        {
            if (n & 1)
            {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return res;
    }

    long long comb(int n, int m)
    {
        return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
    }
    void init()
    {
        if (fact[0])
        {
            return;
        }
        fact[0] = 1;
        for (int i = 1; i < MX; i++)
        {
            fact[i] = fact[i - 1] * i % MOD;
        }

        inv_fact[MX - 1] = qpow(fact[MX - 1], MOD - 2);
        for (int i = MX - 1; i; i--)
        {
            inv_fact[i - 1] = inv_fact[i] * i % MOD;
        }
    }

public:
    int countGoodArrays(int n, int m, int k)
    {
        init();
        return comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD;
    }
};
