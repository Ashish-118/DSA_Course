class Solution
{
public:
    int solve(vector<int> &nums1, vector<int> &nums2, bool swapped, int index, vector<vector<int>> &dp)
    {
        if (index == nums1.size())
            return 0;

        if (dp[index][swapped] != -1)
            return dp[index][swapped];
        int ans = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        if (swapped)
            swap(prev1, prev2);

        // no swap case
        if (prev1 < nums1[index] && prev2 < nums2[index])
        {
            ans = min(ans, solve(nums1, nums2, false, index + 1, dp));
        }

        // swap case
        if (prev2 < nums1[index] && prev1 < nums2[index])
        {
            ans = min(ans, 1 + solve(nums1, nums2, true, index + 1, dp));
        }
        dp[index][swapped] = ans;
        return ans;
    }

    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(nums1, nums2, false, 1, dp);
    }
};

// tabulation

class Solution
{
public:
    int solve(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 1; i--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int prev1 = nums1[i - 1];
                int prev2 = nums2[i - 1];

                if (swapped)
                    swap(prev1, prev2);

                int ans = INT_MAX;

                // No swap
                if (nums1[i] > prev1 && nums2[i] > prev2)
                    ans = dp[i + 1][0];

                // Swap
                if (nums1[i] > prev2 && nums2[i] > prev1)
                    ans = min(ans, 1 + dp[i + 1][1]);

                dp[i][swapped] = ans;
            }
        }

        return dp[1][0];
    }

    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        // Add dummy -1 to handle i-1 = 0 case safely
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        return solve(nums1, nums2);
    }
};

//
// space optimized version

class Solution
{
public:
    int solve(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int Swap = 0, noswap = 0, currswap = 0, nocurrswap = 0;

        for (int i = n - 1; i >= 1; i--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int prev1 = nums1[i - 1];
                int prev2 = nums2[i - 1];

                if (swapped)
                    swap(prev1, prev2);

                int ans = INT_MAX;

                if (nums1[i] > prev1 && nums2[i] > prev2)
                    ans = noswap;

                if (nums1[i] > prev2 && nums2[i] > prev1)
                    ans = min(ans, 1 + Swap);

                if (swapped)
                    currswap = ans;
                else
                    nocurrswap = ans;
            }
            Swap = currswap;
            noswap = nocurrswap;
        }

        return nocurrswap;
    }

    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {

        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        return solve(nums1, nums2);
    }
};
