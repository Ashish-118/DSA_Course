#define mod 1000000007
class Solution
{
public:
    int sum(int a, int b)
    {
        return ((a % mod) + (b % mod)) % mod;
    }

    // int solve(int dice, int faces, int target, vector<vector<int>>& dp){
    //     if (target < 0) return 0;
    //     if (dice == 0 && target == 0) return 1;
    //     if (dice == 0 || target == 0) return 0;

    //     if (dp[dice][target] != -1) return dp[dice][target];

    //     int ans = 0;
    //     for (int i = 1; i <= faces; i++) {
    //         ans = sum(ans, solve(dice - 1, faces, target - i, dp));
    //     }

    //     dp[dice][target] = ans;
    //     return ans;
    // }

    int solveTab(int dice, int faces, int target)
    {
        vector<vector<int>> dp(dice + 1, vector<int>(target + 1, 0));

        dp[0][0] = 1;

        for (int d = 1; d <= dice; d++)
        {
            for (int tar = 1; tar <= target; tar++)
            {
                int ans = 0;
                for (int face = 1; face <= faces; face++)
                {
                    if (tar - face >= 0)
                    {
                        ans = sum(ans, dp[d - 1][tar - face]);
                    }
                }
                dp[d][tar] = ans;
            }
        }
        return dp[dice][target];
    }

    int optimised(int dice, int faces, int target)
    {
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);

        prev[0] = 1;

        for (int d = 1; d <= dice; d++)
        {
            for (int tar = 1; tar <= target; tar++)
            {
                int ans = 0;
                for (int face = 1; face <= faces; face++)
                {
                    if (tar - face >= 0)
                    {
                        ans = sum(ans, prev[tar - face]);
                    }
                }
                curr[tar] = ans;
            }
            prev = curr;
        }
        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target)
    {
        // vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return optimised(n, k, target);
    }
};
