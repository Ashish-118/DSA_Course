class Solution
{
public:
    int t[501][501][3];
    int solve(int i, int j, vector<vector<int>> &coins, int token)
    {
        if (i >= coins.size() - 1 && j >= coins[0].size() - 1)
        {
            return (token < 2 && coins[i][j] < 0 ? 0 : coins[i][j]);
        }
        else if (i >= coins.size() || j >= coins[0].size())
        {
            return INT_MIN;
        }

        if (t[i][j][token] != INT_MIN)
            return t[i][j][token];

        int rightWithToken = INT_MIN;
        int rightWithoutToken = INT_MIN;
        int downWithToken = INT_MIN;
        int downWithoutToken = INT_MIN;

        if (coins[i][j] < 0 && token < 2)
        {
            rightWithToken = solve(i, j + 1, coins, token + 1);
            downWithToken = solve(i + 1, j, coins, token + 1);
        }

        rightWithoutToken = solve(i, j + 1, coins, token);
        if (rightWithoutToken != INT_MIN)
        {
            rightWithoutToken += coins[i][j];
        }
        downWithoutToken = solve(i + 1, j, coins, token);
        if (downWithoutToken != INT_MIN)
        {
            downWithoutToken += coins[i][j];
        }

        return t[i][j][token] = max({rightWithToken, rightWithoutToken,
                                     downWithToken, downWithoutToken});
    }
    int maximumAmount(vector<vector<int>> &coins)
    {
        // memset(t, , sizeof(t));// we cannot use this to initialize with INT_MIN, the reason for this is in the concept diary -> cpp section
        for (int i = 0; i < 501; i++)
        {
            for (int j = 0; j < 501; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    t[i][j][k] = INT_MIN;
                }
            }
        }

        return solve(0, 0, coins, 0);
    }
};