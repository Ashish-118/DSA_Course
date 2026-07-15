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


// optimization using tabulation

#define mod 1000000007
class Solution
{
public:
    vector<vector<vector<int>>> t;
    int solve(int i, int gcd_a, int gcd_b, vector<int> &nums)
    {
        if (i >= nums.size())
        {
            if (gcd_b && gcd_a)
            {
                if (gcd_a == gcd_b)
                {
                    return 1;
                }
            }

            return 0;
        }

        if (t[i][gcd_a][gcd_b] != -1)
            return t[i][gcd_a][gcd_b];

        int a = solve(i + 1, gcd(gcd_a, nums[i]), gcd_b, nums);
        int b = solve(i + 1, gcd_a, gcd(gcd_b, nums[i]), nums);

        int skip = solve(i + 1, gcd_a, gcd_b, nums);

        return t[i][gcd_a][gcd_b] = (1LL * a + b + skip) % mod;
    }
    int subsequencePairCount(vector<int> &nums)
    {
        int n = nums.size();
        int maxEl = -1;
        for (int x : nums)
            maxEl = max(maxEl, x);

        // t.assign(n + 1, vector<vector<int>>(maxEl+1, vector<int>(maxEl+1,
        // 0))); return solve(0, 0, 0, nums);

        // tabulation approach

        // for (int gcd = 1; gcd <= maxEl; gcd++) {
        //     t[n][gcd][gcd] = 1;
        // }

        // for (int i = n - 1; i >= 0; i--) {
        //     for (int gcd_a = 0; gcd_a <= maxEl; gcd_a++) {
        //         for (int gcd_b = 0; gcd_b <= maxEl; gcd_b++) {

        //             int a = t[i + 1][gcd(gcd_a, nums[i])][gcd_b];
        //             int b = t[i + 1][gcd_a][gcd(gcd_b, nums[i])];
        //             int skip = t[i + 1][gcd_a][gcd_b];

        //             t[i][gcd_a][gcd_b] = (1LL * a + b + skip) % mod;
        //         }
        //     }
        // }

        // return t[0][0][0];

        vector<vector<int>> successor(maxEl + 1, vector<int>(maxEl + 1, 0));
        vector<vector<int>> current(maxEl + 1, vector<int>(maxEl + 1, 0));

        for (int gcd = 1; gcd <= maxEl; gcd++)
        {
            successor[gcd][gcd] = 1;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int gcd_a = 0; gcd_a <= maxEl; gcd_a++)
            {
                for (int gcd_b = 0; gcd_b <= maxEl; gcd_b++)
                {

                    int a = successor[gcd(gcd_a, nums[i])][gcd_b];
                    int b = successor[gcd_a][gcd(gcd_b, nums[i])];
                    int skip = successor[gcd_a][gcd_b];

                    current[gcd_a][gcd_b] = (1LL * a + b + skip) % mod;
                }
            }

            successor = current;
        }

        return current[0][0];
    }
};