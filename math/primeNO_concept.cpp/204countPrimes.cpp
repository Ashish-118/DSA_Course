class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> sieve(n + 1, true);
        sieve[1] = false;
        sieve[0] = false;

        for (int i = 2; i < n; i++)
        {
            if (!sieve[i])
                continue;

            for (int j = i + i; j < n; j = j + i)
            {
                sieve[j] = false;
            }
        }

        int count = 0;
        for (int i = 1; i < n; i++)
        {
            if (sieve[i])
                count++;
        }
        return count;
    }
};
// time complexity:  O(n log log n)

// optimal
class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> sieve(n + 1, true);
        sieve[1] = false;
        sieve[0] = false;

        for (int i = 2; i * i <= n; i++)
        {
            if (sieve[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    sieve[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 1; i < n; i++)
        {
            if (sieve[i])
                count++;
        }
        return count;
    }
};

// time complexity: O(n log log n)