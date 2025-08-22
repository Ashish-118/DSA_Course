// recurrsionn with memoization form

class Solution
{
public:
    int solve(int index, vector<int> &nums, vector<int> &dp)
    {
        if (index == nums.size() - 1)
            return 1;
        if (dp[index] != -1)
            return dp[index];
        int ans = 0;

        for (int i = 1; i <= nums[index] && !ans; i++)
        {
            ans |= solve(index + i, nums, dp);
        }

        return dp[index] = ans;
    }
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};

// tabulation form

class Solution
{
public:
    int solve(vector<int> &nums, vector<int> &dp)
    {
        int n = nums.size();
        dp[0] = true;
        for (int i = 0; i < n && dp[i]; i++)
        {
            for (int j = 1; j <= nums[i]; j++)
            {
                if ((i + j) >= n)
                {
                    break;
                }

                dp[i + j] = 1;
            }
            if (dp[n - 1])
                return 1;
        }
        return 0;
    }
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        return solve(nums, dp);
    }
};