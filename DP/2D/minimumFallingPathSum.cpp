class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for (int row = n - 1; row >= 0; row--)
        {
            for (int i = 0; i < n; i++)
            {
                int below = prev[i];
                int diagonalRight = INT_MAX;
                if ((i + 1) < n)
                    diagonalRight = prev[i + 1];

                int diagonalLeft = INT_MAX;
                if ((i - 1) >= 0)
                    diagonalLeft = prev[i - 1];

                curr[i] = min({diagonalLeft, diagonalRight, below}) + matrix[row][i];
            }
            prev = curr;
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            ans = min(ans, prev[i]);

        return ans;
    }
};