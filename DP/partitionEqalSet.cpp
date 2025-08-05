class Solution
{
public:
    bool solve(int index, vector<int> &nums, int N, int target, vector<vector<int>> &dp)
    {
        // base case
        if (index >= N)
        {
            return false;
        }
        if (target < 0)
        {
            return false;
        }
        if (target == 0)
        {
            return true;
        }

        if (dp[index][target] != -1)
            return dp[index][target];
        bool incl = solve(index + 1, nums, N, target - nums[index], dp);
        bool excl = solve(index + 1, nums, N, target - 0, dp);

        return dp[index][target] = incl or excl;
    }

    bool Tab(int target, vector<int> &nums, int n)
    {
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base case: sum = 0 is always possible
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        // Base case: first element can form subset only if it's <= target
        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++)
        {
            for (int t = 1; t <= target; t++)
            {
                bool notTake = dp[i - 1][t];
                bool take = false;
                if (nums[i] <= t)
                    take = dp[i - 1][t - nums[i]];
                dp[i][t] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }

    bool optimised(int target, vector<int> &nums, int n)
    {
        vector<bool> curr(target + 1, false);
        vector<bool> prev(target + 1, false);

        prev[0] = true;
        curr[0] = true;
        for (int i = 0; i < n; i++)
        {

            for (int t = 1; t <= target; t++)
            {
                bool notTake = prev[t];
                bool take = false;
                if (nums[i] <= t)
                    take = prev[t - nums[i]];
                curr[t] = take || notTake;
            }
            prev = curr;
        }
        return prev[target];
    }

    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0;

        for (auto &x : nums)
            sum += x;
        if (sum & 1)
            return false;
        //    vector<vector<int>> dp(n+1,vector<int>((sum/2)+1,-1));
        // return solve(0,nums,n,sum/2,dp);

        return optimised(sum / 2, nums, n);
    }
};