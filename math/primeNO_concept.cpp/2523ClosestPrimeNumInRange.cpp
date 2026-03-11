class Solution
{
public:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;

        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }

        return true;
    }
    vector<int> closestPrimes(int left, int right)
    {
        vector<int> primes;

        for (int i = left; i <= right; i++)
        {
            if (isPrime(i))
                primes.push_back(i);
        }

        int diff = INT_MAX;
        vector<int> ans = {-1, -1};

        int len = primes.size();

        for (int i = 0; i < len - 1; i++)
        {
            int d = primes[i + 1] - primes[i];
            if (d < diff)
            {
                diff = d;
                ans = {primes[i], primes[i + 1]};
            }
            else if (d == diff && ans[0] > primes[i])
            {
                ans = {primes[i], primes[i + 1]};
            }
        }

        return ans;
    }
};

// optimal approach: using sieve of eratosthenes

class Solution
{
public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i * i <= right; i++)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= right; j += i)
                    isPrime[j] = false;
            }
        }

        vector<int> primes;

        for (int i = left; i <= right; i++)
        {
            if (isPrime[i])
                primes.push_back(i);
        }

        int diff = INT_MAX;
        vector<int> ans = {-1, -1};

        int len = primes.size();

        for (int i = 0; i < len - 1; i++)
        {
            int d = primes[i + 1] - primes[i];
            if (d < diff)
            {
                diff = d;
                ans = {primes[i], primes[i + 1]};
            }
            else if (d == diff && ans[0] > primes[i])
            {
                ans = {primes[i], primes[i + 1]};
            }
        }

        return ans;
    }
};