class Solution
{
public:
    int solve(vector<int> &nums, int i, int c, vector<int> &dp)
    {
        if (i >= c)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int take = nums[i] + solve(nums, i + 2, c, dp);
        int notTake = 0 + solve(nums, i + 1, c, dp);

        return dp[i] = max(take, notTake);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, -1);
        if (n == 1)
            return nums[0];
        int withFirstElement = solve(nums, 0, n - 1, dp);
        dp.assign(n, -1);
        int withoutFirstElement = solve(nums, 1, n, dp);

        return max(withFirstElement, withoutFirstElement);
    }
};

// tabulation approach

class Solution
{
public:
    int solve(vector<int> &nums, int index, int c, vector<int> &dp)
    {

        for (int i = index; i < c; i++)
        {
            int take = ((i - 2) >= index ? nums[i] + dp[i - 2] : nums[i]);
            int notTake = ((i - 1) >= index ? 0 + dp[i - 1] : nums[i]);
            dp[i] = max(take, notTake);
        }

        return dp[c - 1];
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, 0);
        if (n == 1)
            return nums[0];
        int withFirstElement = solve(nums, 0, n - 1, dp);
        cout << withFirstElement << endl;
        dp.assign(n, 0);
        int withoutFirstElement = solve(nums, 1, n, dp);
        cout << withoutFirstElement << endl;

        return max(withFirstElement, withoutFirstElement);
    }
};

// space optimization approach

class Solution
{
public:
    int solve(vector<int> &nums, int index, int c)
    {

        int prev2 = 0;
        int prev1 = 0;
        for (int i = index; i < c; i++)
        {
            int take = ((i - 2) >= index ? nums[i] + prev2 : nums[i]);
            int notTake = ((i - 1) >= index ? 0 + prev1 : 0);
            prev2 = prev1;
            prev1 = max(take, notTake);
        }

        return prev1;
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];
        int withFirstElement = solve(nums, 0, n - 1);
        cout << withFirstElement << endl;

        int withoutFirstElement = solve(nums, 1, n);
        cout << withoutFirstElement << endl;

        return max(withFirstElement, withoutFirstElement);
    }
};