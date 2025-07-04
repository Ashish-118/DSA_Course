// class Solution
// {
// public:
//     int solveDp(vector<int> &coins, int x, vector<int> &dp)
//     {
//         if (x == 0)
//             return 0;
//         if (x < 0)
//             return INT_MAX;

//         if (dp[x] != -1)
//             return dp[x];

//         int mini = INT_MAX;

//         for (auto coin : coins)
//         {

//             int ans = solveDp(coins, x - coin, dp);
//             if (ans != INT_MAX)
//             {
//                 mini = min(mini, 1 + ans);
//             }
//         }

//         dp[x] = mini;
//         return dp[x];
//     }

//     int coinChange(vector<int> &coins, int amount)
//     {
//         vector<int> dp(amount + 1, -1);
//         int final = solveDp(coins, amount, dp);
//         return (final != INT_MAX) ? final : -1;
//     }
// };

///
