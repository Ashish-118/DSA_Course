class Solution
{
public:
    int maxProductPath(vector<vector<int>> &grid)
    {
        const int mod = 1000000000 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> maxgt(m, vector<long long>(n));
        vector<vector<long long>> minlt(m, vector<long long>(n));

        maxgt[0][0] = minlt[0][0] = grid[0][0];
        for (int i = 1; i < n; i++)
        {
            maxgt[0][i] = minlt[0][i] = maxgt[0][i - 1] * grid[0][i];
        }
        for (int i = 1; i < m; i++)
        {
            maxgt[i][0] = minlt[i][0] = maxgt[i - 1][0] * grid[i][0];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (grid[i][j] >= 0)
                {
                    maxgt[i][j] =
                        max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
                    minlt[i][j] =
                        min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
                }
                else
                {
                    maxgt[i][j] =
                        min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
                    minlt[i][j] =
                        max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
                }
            }
        }
        if (maxgt[m - 1][n - 1] < 0)
        {
            return -1;
        }
        else
        {
            return maxgt[m - 1][n - 1] % mod;
        }
    }
};

/// optimised bottom up approach with space optimisation

int maxProductPath(vector<vector<int>> &grid)
{
    m = grid.size();
    n = grid[0].size();

    // t = vector<vector<pair<ll, ll>>>( m, vector<pair<ll, ll>>(n,
    // {LLONG_MIN, LLONG_MAX}));

    //  vector<pair<ll, ll>>curr( m, vector<pair<ll, ll>>(n, {LLONG_MIN,
    //  LLONG_MAX}));

    // t[m - 1][n - 1] = {grid[m - 1][n - 1], grid[m - 1][n - 1]};
    vector<pair<ll, ll>> prev(n, {LLONG_MIN, LLONG_MAX});
    vector<pair<ll, ll>> curr(n, {LLONG_MIN, LLONG_MAX});

    for (int i = m - 1; i >= 0; i--)
    {

        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
            {
                curr[j] = {grid[m - 1][n - 1], grid[m - 1][n - 1]};
                continue;
            }
            ll maxVal = LLONG_MIN;
            ll minVal = LLONG_MAX;

            // Down
            if (i + 1 < m)
            {
                auto [downMax, downMin] = prev[j];
                maxVal = max(
                    {maxVal, grid[i][j] * downMax, grid[i][j] * downMin});
                minVal = min(
                    {minVal, grid[i][j] * downMax, grid[i][j] * downMin});
            }

            // Right
            if (j + 1 < n)
            {
                auto [rightMax, rightMin] = curr[j + 1];
                maxVal = max(
                    {maxVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
                minVal = min(
                    {minVal, grid[i][j] * rightMax, grid[i][j] * rightMin});
            }

            curr[j] = {maxVal, minVal};
        }

        prev = curr;
        fill(begin(curr), end(curr), make_pair(LLONG_MIN, LLONG_MAX));
    }

    return prev[0].first < 0 ? -1 : prev[0].first % MOD;
}
}
;