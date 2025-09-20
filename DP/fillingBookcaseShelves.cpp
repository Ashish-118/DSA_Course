class Solution
{
public:
    int dp[1001][1001];

    int solve(int i, int remainingWidth, int maxHeight, vector<vector<int>> &books, int shelfWidth)
    {
        if (i >= books.size())
            return maxHeight;
        if (dp[i][remainingWidth] != -1)
            return dp[i][remainingWidth];

        int bookH = books[i][1];
        int bookW = books[i][0];

        // keep
        int keep = INT_MAX;
        if (bookW <= remainingWidth)
        {
            keep = solve(i + 1, remainingWidth - bookW, max(maxHeight, bookH), books, shelfWidth);
        }

        int skip = maxHeight + solve(i + 1, shelfWidth - bookW, bookH, books, shelfWidth);

        return dp[i][remainingWidth] = min(keep, skip);
    }
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, shelfWidth, 0, books, shelfWidth);
    }
}; // reccursive+memoization