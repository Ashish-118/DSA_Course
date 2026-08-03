class Solution
{
public:
    // int t[501][501];
    // int solve(vector<int>& piles, int i, int j) {
    //     if (i > j)
    //         return 0;
    //     if (t[i][j] != -1)
    //         return t[i][j];

    //     int commonCase = solve(piles, i + 1, j - 1);
    //     int takeStart = piles[i] + max(solve(piles, i + 2, j), commonCase);
    //     int takeEnd = piles[j] + max(solve(piles, i, j - 2), commonCase);
    //     return t[i][j] = max(takeStart, takeEnd);
    // }

    bool stoneGame(vector<int> &piles)
    {
        // int sum = accumulate(begin(piles), end(piles), 0);
        // memset(t, 0, sizeof(t));
        // int n = piles.size();
        // // int val = solve(piles, 0, piles.size() - 1);

        // // return val > sum / 2;

        // // bottom up

        // for (int i = n-1; i>=0; i--) {
        //     for (int j = i + 1; j < n; j++) {
        //         int commonCase =
        //             ((i + 1 <= j - 1 && i + 1 < n && j > 0) ? t[i + 1][j - 1]
        //                                                     : 0);
        //         int takeStartV1 = (i + 2 < n && i + 2 <= j) ? t[i + 2][j] : 0;
        //         int takeEndV1 = (j > 1 && i <= j - 2) ? t[i][j - 2] : 0;

        //         int takeStart = piles[i] + max(takeStartV1, commonCase);

        //         int takeEnd = piles[j] + max(takeEndV1, commonCase);
        //         t[i][j] = max(takeStart, takeEnd);
        //     }
        // }

        // cout << t[0][n - 1];

        // return t[0][n - 1] > sum / 2;

        //-----------one liner sol: because alice will always win no matter what

        return true;
    }
};