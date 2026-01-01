#include <bits/stdc++.h>

int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = 1e9;

    for (int k = i; k < j; k++)
    {
        int operations = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);

        if (operations < mini)
        {
            mini = operations;
        }
    }

    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return solve(1, N - 1, arr, dp);
}

// bottom up

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int len = 2; len < N; len++)
    {
        for (int i = 1; i + len - 1 < N; i++)
        {
            int j = i + len - 1;
            dp[i][j] = 1e9;

            for (int k = i; k < j; k++)
            {
                int operations =
                    arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];

                dp[i][j] = min(dp[i][j], operations);
            }
        }
    }

    return dp[1][N - 1];
}
