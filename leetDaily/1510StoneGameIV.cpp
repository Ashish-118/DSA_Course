class Solution
{
public:
    int t[100000][2];
    int solve(int n, int player)
    {
        if (n <= 0)
        {
            if (player)
                return 0;
            else
                return 1;
        }

        if (t[n][player] != -1)
            return t[n][player];

        int root = sqrt(n);
        for (int i = 1; i <= root; i++)
        {
            if (player)
            {
                if (solve(n - (i * i), 0))
                {
                    return t[n][player] = 1;
                }
            }
            else
            {
                if (!solve(n - (i * i), 1))
                {
                    return t[n][player] = 0;
                }
            }
        }

        return t[n][player] = player ? 0 : 1;
    }
    bool winnerSquareGame(int n)
    {
        memset(t, -1, sizeof(t));
        return solve(n, 1);
    }
};