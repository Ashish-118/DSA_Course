class Solution
{
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    vector<vector<bool>> visited2;
    vector<vector<bool>> visited1;

    vector<vector<int>> newGrid;

    bool poss(int i, int j, int n, int base)
    {
        if (i == n - 1 && j == n - 1)
        {
            return true;
        }

        visited2[i][j] = true;

        for (auto d : dir)
        {
            int x_ = i + d.first;
            int y_ = j + d.second;

            if (x_ >= n || y_ >= n || x_ < 0 || y_ < 0 || visited2[x_][y_] ||
                newGrid[x_][y_] < base)
                continue;

            if (poss(x_, y_, n, base))
            {
                return true;
            }
        }

        return false;
    }
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();

        newGrid.assign(n, vector<int>(n, -1));
        visited1.assign(n, vector<bool>(n, false));
        vector<pair<int, int>> thieves;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    newGrid[i][j] = 0;
                    visited1[i][j] = true;
                }
            }
        }

        int lvl = 0;

        while (!q.empty())
        {
            int len = q.size();

            while (len--)
            {
                auto [x, y] = q.front();
                q.pop();

                for (auto d : dir)
                {
                    int x_ = x + d.first;
                    int y_ = y + d.second;

                    if (x_ >= n || y_ >= n || x_ < 0 || y_ < 0 ||
                        visited1[x_][y_])
                        continue;

                    q.push({x_, y_});
                    visited1[x_][y_] = true;
                    newGrid[x_][y_] = lvl + 1;
                }
            }
            lvl++;
        }

        int lo = 0, hi = min(newGrid[0][0], newGrid[n - 1][n - 1]);
        int ans = -1;
        while (lo <= hi)
        {
            visited2.assign(n, vector<bool>(n, false));
            int mid = lo + (hi - lo) / 2;
            if (poss(0, 0, n, mid))
            {
                lo = mid + 1;
                ans = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return ans;
    }
};