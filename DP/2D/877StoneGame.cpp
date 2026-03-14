class Solution
{
public:
    int t[501][501];
    int solve(vector<int> &piles, int i, int j)
    {
        if (i > j)
            return 0;
        if (t[i][j] != -1)
            return t[i][j];

        int commonCase = solve(piles, i + 1, j - 1);
        int takeStart = piles[i] + max(solve(piles, i + 2, j), commonCase);
        int takeEnd = piles[j] + max(solve(piles, i, j - 2), commonCase);
        return t[i][j] = max(takeStart, takeEnd);
    }
    bool stoneGame(vector<int> &piles)
    {
        int sum = accumulate(begin(piles), end(piles), 0);
        memset(t, -1, sizeof(t));
        int val = solve(piles, 0, piles.size() - 1);

        return val > sum / 2;
    }
};