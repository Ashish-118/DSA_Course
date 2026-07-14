#define mod 1000000007

class Solution
{
public:
    unordered_map<long long, int> dp;

    long long getKey(int i, int gcd_a, int gcd_b, int used_a, int used_b)
    {
        return ((((1LL * i * 201 + gcd_a) * 201 + gcd_b) * 2 + used_a) * 2 +
                used_b);
    }

    int solve(int i, int gcd_a, int gcd_b, int used_a, int used_b,
              vector<int> &nums)
    {

        if (i == nums.size())
        {
            return (used_a && used_b && gcd_a == gcd_b);
        }

        long long key = getKey(i, gcd_a, gcd_b, used_a, used_b);

        if (dp.count(key))
            return dp[key];

        long long ans = 0;

        ans += solve(i + 1, gcd(gcd_a, nums[i]), gcd_b, 1, used_b, nums);

        ans += solve(i + 1, gcd_a, gcd(gcd_b, nums[i]), used_a, 1, nums);

        ans += solve(i + 1, gcd_a, gcd_b, used_a, used_b, nums);

        return dp[key] = ans % mod;
    }

    int subsequencePairCount(vector<int> &nums)
    {
        dp.clear();
        return solve(0, 0, 0, 0, 0, nums);
    }
};