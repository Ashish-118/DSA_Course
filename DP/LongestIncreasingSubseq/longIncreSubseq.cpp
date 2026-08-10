class Solution
{
public:
    int solve(vector<int> &nums, int prev, int curr, int n, vector<int> &dp)
    {
        if (curr >= n)
            return 0;
        int maxi = 0;
        if (dp[curr] != -1)
            return dp[curr];

        for (int i = curr; i < n; i++)
        {
            if (curr == 0 || nums[prev] < nums[i])
            {
                maxi = max(maxi, solve(nums, i, i + 1, n, dp) + 1);
            }
        }
        dp[curr] = maxi;
        return maxi;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, 0, 0, n, dp);
    }
}; // memoization method

// tabulation method
class Solution
{
public:
    int solve(vector<int> &nums, int n, vector<int> &dp)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            int maxi = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] < nums[j])
                {
                    maxi = max(maxi, dp[j] + 1);
                }
            }
            dp[i] = maxi;
        }
        int ans = 0;
        for (auto x : dp)
            ans = max(ans, x);
        return ans + 1;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        return solve(nums, n, dp);
    }
};

// dp+binary search method
class Solution
{
public:
    int solve(vector<int> &nums, int n)
    {
        if (n == 0)
            return 0;
        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < n; i++)
        {
            if (ans.back() < nums[i])
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        return solve(nums, n);
    }
};

// babbar's memoization method
class Solution
{
public:
    int solve(int n, vector<int> &nums, int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr == n)
        {
            return 0;
        }
        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];
        // include
        int take = 0;
        if (prev == -1 || nums[curr] > nums[prev])
            take = 1 + solve(n, nums, curr + 1, curr, dp);
        // exclude
        int notTake = 0 + solve(n, nums, curr + 1, prev, dp);
        dp[curr][prev + 1] = max(take, notTake);
        return dp[curr][prev + 1];
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(n, nums, 0, -1, dp);
    }
};