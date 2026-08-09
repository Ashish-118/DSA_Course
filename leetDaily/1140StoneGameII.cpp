class Solution
{
public:
    int t[101][101][2];
    int solve(int i, int player, int M, vector<int> &piles)
    {
        int n = piles.size();
        if (i >= n)
            return 0;

        if (t[i][M][player] != -1)
            return t[i][M][player];

        int score;

        if (player)
        { // alice
            score = 0;
            int sum = 0;
            for (int x = 0; x < min(n - i, 2 * M); x++)
            {
                sum += piles[x + i];

                score =
                    max(score, sum + solve(x + i + 1, 0, max(x + 1, M), piles));
            }
        }
        else
        {
            score = INT_MAX;
            for (int x = 0; x < min(n - i, 2 * M); x++)
            {
                score = min(score, solve(x + i + 1, 1, max(x + 1, M), piles));
            }
        }

        return t[i][M][player] = score;
    }

    int stoneGameII(vector<int> &piles)
    {
        memset(t, -1, sizeof(t));
        return solve(0, 1, 1, piles);
    }
};