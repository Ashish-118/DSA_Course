class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        int k = primes.size();

        vector<long long> ugly(n + 1);
        ugly[1] = 1;

        // idx[j] = pointer for primes[j]
        vector<int> idx(k, 1);

        for (int i = 2; i <= n; i++)
        {
            long long nextUgly = LLONG_MAX;

            // find next ugly
            for (int j = 0; j < k; j++)
            {
                nextUgly = min(nextUgly, ugly[idx[j]] * primes[j]);
            }

            ugly[i] = nextUgly;

            // move all pointers that generated nextUgly
            for (int j = 0; j < k; j++)
            {
                if (ugly[idx[j]] * primes[j] == nextUgly)
                {
                    idx[j]++;
                }
            }
        }

        return (int)ugly[n];
    }
};
