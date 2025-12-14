#define mod 1000000007

class Solution
{

    vector<vector<vector<int>>> dp;
    int M, N, K;

public:
    int solve(int i, int j, int sumRemainder, vector<vector<int>> &grid,
              int k)
    {
        if (i == M - 1 && j == N - 1)
        {
            if ((sumRemainder + grid[i][j]) % k == 0)
                return 1;
            else
                return 0;
        }
        else if (i < 0 || j < 0 || i >= M || j >= N)
            return 0;

        int &cached =
            dp[i][j][sumRemainder]; // cached is the reference means pointing to
                                    // the dp[i][j][sumRemainder]
        if (cached != -1)
            return cached;

        int count =
            (solve(i + 1, j, (sumRemainder + grid[i][j]) % k, grid, k) +
             solve(i, j + 1, (sumRemainder + grid[i][j]) % k, grid, k)) %
            mod;

        return cached = count;
    }

    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        M = grid.size();
        N = grid[0].size();
        K = k;

        // sumRemainder is always in [0, k-1]
        dp.assign(M, vector<vector<int>>(N, vector<int>(K, -1)));

        return solve(0, 0, 0, grid, k);
    }
};
// time complexity: O(M*N*K)
// space complexity: O(M*N*K)