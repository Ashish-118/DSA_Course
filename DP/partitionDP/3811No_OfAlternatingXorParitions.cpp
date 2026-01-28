

class Solution
{
public:
    int mod = 1000000007;
    int t[100001][2];
    int solve(int i, int n, vector<int> &nums, int t1, int t2, int toggle)
    {
        if (i >= n)
            return 1;

        if (t[i][toggle] != -1)
            return t[i][toggle];

        int ans = 0;

        int x_or = 0;

        for (int k = i; k < n; k++)
        {
            x_or ^= nums[k];
            if (toggle && x_or == t2)
            { // odd
                ans = (ans + solve(k + 1, n, nums, t1, t2, !toggle)) % mod;
            }
            else if (!toggle && x_or == t1)
            { // even
                ans = (ans + solve(k + 1, n, nums, t1, t2, !toggle)) % mod;
            }
        }

        return t[i][toggle] = ans;
    }

    int alternatingXOR(vector<int> &nums, int target1, int target2)
    {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        // return solve(0, n, nums, target1, target2, 0);

        // bottom up
        t[n][0] = 1;
        t[n][1] = 1;

        for (int i = n - 1; i >= 0; i--)
        {

            int ans = 0;

            int x_or = 0;

            // when the curr == t2(odd) next substring ==t1
            for (int k = i; k < n; k++)
            {
                x_or ^= nums[k];

                if (x_or == target2)
                {
                    ans = (ans + t[k + 1][0]) % mod;
                }
            }
            t[i][1] = ans;

            ans = 0;
            x_or = 0;

            for (int k = i; k < n; k++)
            {
                x_or ^= nums[k];
                if (x_or == target1)
                {
                    ans = (ans + t[k + 1][1]) % mod;
                }
            }
            t[i][0] = ans;
        }

        return t[0][0];
    }
};

// the most optimal solution
// video solution-- https://www.youtube.com/watch?v=U74N1BaQPcI
class Solution
{
public:
    int alternatingXOR(vector<int> &nums, int target1, int target2)
    {
        const int MOD = 1e9 + 7;

        unordered_map<int, long long> map1, map2;

        // Base case: we are saying that we have seen target2 by inserting 0 in map2 and we know that the first block has to be target1 , so this is like saying we have one way to have first block as target1
        map2[0] = 1;

        int x = 0; // prefix XOR
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            x ^= nums[i];

            // If current block XOR becomes target1,  then we are checking in map2 that if have seen target2 i.e (x ^ target1) before
            long long endsWithTarget1 =
                map2.count(x ^ target1) ? map2[x ^ target1] : 0;

            // If current block XOR becomes target2, then we are checking in map1 that if have seen target1 i.e (x ^ target2) before
            long long endsWithTarget2 =
                map1.count(x ^ target2) ? map1[x ^ target2] : 0;

            // Update maps
            map1[x] = (map1[x] + endsWithTarget1) % MOD;
            map2[x] = (map2[x] + endsWithTarget2) % MOD;

            if (i == nums.size() - 1)
            {
                ans = (endsWithTarget1 + endsWithTarget2) % MOD;
            }
        }

        return ans;
    }
};
