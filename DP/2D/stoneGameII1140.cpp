class Solution
{
public:
    int t[101][201];
    vector<int> prefixSum;

    int solve(int i, int M, vector<int> &piles, int n)
    {
        if (i >= n)
            return 0;
        if (t[i][M] != -1)
            return t[i][M];
        int ans = 0;

        for (int k = 1; k <= 2 * M; k++)
        {
            if (i + k - 1 >= n)
                break;

            int val = prefixSum[i + k - 1] - (i > 0 ? prefixSum[i - 1] : 0);

            int M1 = max(M, k);
            int MinMaxi = INT_MAX;
            for (int x = 1; x <= 2 * M1; x++)
            {

                MinMaxi = min(MinMaxi, solve(i + k + x, max(x, M1), piles, n));
            }

            ans = max(ans, val + MinMaxi);
        }

        return t[i][M] = ans;
    }
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();
        prefixSum = vector<int>(n, 0);
        prefixSum[0] = piles[0];
        memset(t, -1, sizeof(t));

        for (int i = 1; i < n; i++)
        {
            prefixSum[i] = piles[i] + prefixSum[i - 1];
        }

        return solve(0, 1, piles, n);
    }
};