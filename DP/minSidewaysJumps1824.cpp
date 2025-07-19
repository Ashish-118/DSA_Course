class Solution
{
public:
    int solve(vector<int> &obs, int i, int lane, vector<vector<int>> &dp)
    {
        if (i == (obs.size() - 1))
            return 0;

        if (dp[lane][i] != -1)
            return dp[lane][i];
        int jumps = INT_MAX;

        for (int j = 1; j <= 3; j++)
        {
            if (j == lane && lane != obs[i] && obs[i + 1] != lane)
            {
                jumps = min(jumps, solve(obs, i + 1, lane, dp));
            }
            else
            {
                if (j != lane && obs[i] != j)
                {
                    jumps = min(jumps, solve(obs, i + 1, j, dp) + 1);
                }
            }
        }
        dp[lane][i] = jumps;
        return jumps;
    }

    int minSideJumps(vector<int> &obstacles)
    {
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));

        return solve(obstacles, 0, 2, dp);
    }
};