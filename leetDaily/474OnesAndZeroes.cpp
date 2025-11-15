class Solution
{
public:
    // int dp[602][101][101];
    // int solve(vector<string>& strs, int m, int n, int i) {
    //     if (i >= strs.size()) {
    //         return 0;
    //     }

    //     if (dp[i][m][n] != -1)
    //         return dp[i][m][n];
    //     int ones = count(begin(strs[i]), end(strs[i]), '1');
    //     int zeroes = count(begin(strs[i]), end(strs[i]), '0');
    //     // take
    //     int take = 0;
    //     if (m - zeroes >= 0 && n - ones >= 0) {
    //         take = 1 + solve(strs, m - zeroes, n - ones, i + 1);
    //     }

    //     int notTake = solve(strs, m, n, i + 1);

    //     return dp[i][m][n] = max(take, notTake);
    // }

    int tab(vector<string> &strs, int m, int n)
    {

        vector<vector<int>> curr(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> prev(m + 1, vector<int>(n + 1, 0));

        for (int i = strs.size() - 1; i >= 0; i--)
        {

            int ones = count(begin(strs[i]), end(strs[i]), '1');
            int zeroes = count(begin(strs[i]), end(strs[i]), '0');

            for (int m1 = 0; m1 <= m; m1++)
            {
                for (int n1 = 0; n1 <= n; n1++)
                {

                    int take = 0;
                    if (m1 - zeroes >= 0 && n1 - ones >= 0)
                    {
                        take = 1 + prev[m1 - zeroes][n1 - ones];
                    }

                    int notTake = prev[m1][n1];

                    curr[m1][n1] = max(take, notTake);
                }
            }

            prev = curr;
        }

        return prev[m][n];
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        // memset(dp, 0, sizeof(dp));
        // return solve(strs, m, n, 0);

        return tab(strs, m, n);
    }
};