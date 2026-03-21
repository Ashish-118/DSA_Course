class Solution
{
public:
    static const long long MOD = 1000000007;
    long long modpow(long long a, long long b)
    {
        long long r = 1;
        while (b)
        {
            if (b & 1)
                r = r * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return r;
    }
    long long sumOfNumbers(int l, int r, int k)
    {
        long long cnt = r - l + 1;
        long long S = ((long long)l + r) % MOD * cnt % MOD * modpow(2, MOD - 2) % MOD;
        long long total = 0;
        if (k == 1)
            return S % MOD; // 10^0 = 1
        long long powCnt = modpow(cnt, k - 1);
        long long placeSum = (modpow(10, k) - 1 + MOD) % MOD * modpow(9, MOD - 2) % MOD;
        total = S % MOD * powCnt % MOD * placeSum % MOD;
        return total % MOD;
    }
};