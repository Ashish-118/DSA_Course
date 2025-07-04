// class Solution
// {
// public:
//     // recurrsion stair problem
//     int climbStairs(int n)
//     {
//         vector<int> dp(n + 1);

//         dp[0] = 1;
//         int count = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             dp[i] = dp[i - 1] + ((i - 2) < 0 ? 0 : dp[i - 2]);
//         }
//         return dp[n];
//     }
// };

// space optimization and best solution

class Solution
{
public:
    int climbStairs(int n)
    {
        int prev1 = 1;
        int prev2 = 0;

        for (int i = 1; i <= n; i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
