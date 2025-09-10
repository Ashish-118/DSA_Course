class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {

        queue<pair<int, int>> q;
        q.push({1 + delay, 1 + forget}); //{gotToKnow,ableToSpread,expiry}
        int count = 0;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            int expiry = front.second;
            int start = front.first;

            if (expiry > n)
                count++;

            while (start <= n && start < expiry)
            {
                q.push({start + delay, start + forget});
                start++;
            }
        }

        return count;
    }
}; // although memory limit exceeded but logic is correct

// recurrisve + memoization  for above approach
#define mod 1000000007
class Solution
{
public:
    int add(int a, int b)
    {
        return ((a % mod) + (b % mod)) % mod;
    }

    int solve(int spreadingDate, int expiry, int delay, int forget, int n,
              unordered_map<long long, int> &dp)
    {
        long long key = ((long long)spreadingDate << 32) ^ expiry; // unique pair
        if (dp.count(key))
            return dp[key];

        int count = (expiry > n ? 1 : 0);

        for (int start = spreadingDate; start <= n && start < expiry; start++)
        {
            count = add(count, solve(start + delay, start + forget, delay, forget, n, dp));
        }

        return dp[key] = count;
    }

    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        unordered_map<long long, int> dp; // instead of 2D vector
        return solve(1 + delay, 1 + forget, delay, forget, n, dp);
    }
};
