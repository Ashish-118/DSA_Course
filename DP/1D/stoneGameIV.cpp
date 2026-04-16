class Solution
{
public:
    int dp[100001];

    bool solve(int n)
    {
        if (n == 0)
            return false; // no move → lose

        if (dp[n] != -1)
            return dp[n];

        for (int i = 1; i * i <= n; i++)
        {
            if (!solve(n - i * i))
            {
                return dp[n] = true; // found losing state for opponent
            }
        }

        return dp[n] = false; // all moves lead to opponent win
    }

    bool winnerSquareGame(int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};

// bottom up

bool winnerSquareGame(int n)
{
    memset(dp, 0, sizeof(dp));

    dp[0] = false;

    for (int stones = 1; stones <= n; stones++)
    {

        for (int j = 1; j * j <= stones; j++)
        {
            if (!dp[stones - j * j])
            {
                dp[stones] = true;

                break;
            }
        }
    }

    return dp[n];
}