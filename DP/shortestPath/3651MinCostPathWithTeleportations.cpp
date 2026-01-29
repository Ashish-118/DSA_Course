class Solution
{
public:
    using p = pair<int, pair<int, pair<int, int>>>;
    int minCost(vector<vector<int>> &grid, int k)
    {
        priority_queue<p, vector<p>, greater<p>> pq;

        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dist(
            n, vector<vector<int>>(m, vector<int>(k + 1, INT_MAX)));

        dist[0][0][k] = 0;
        pq.push({0, {k, {0, 0}}});

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int cost = top.first;
            int remainingTeleport = top.second.first;
            int x = top.second.second.first;
            int y = top.second.second.second;

            if (dist[x][y][remainingTeleport] < cost)
                continue;

            if (x == n - 1 && y == m - 1)
                return cost;

            // Right
            if (y + 1 < m &&
                dist[x][y + 1][remainingTeleport] > cost + grid[x][y + 1])
            {
                dist[x][y + 1][remainingTeleport] = cost + grid[x][y + 1];
                pq.push({dist[x][y + 1][remainingTeleport],
                         {remainingTeleport, {x, y + 1}}});
            }

            // Down
            if (x + 1 < n &&
                dist[x + 1][y][remainingTeleport] > cost + grid[x + 1][y])
            {
                dist[x + 1][y][remainingTeleport] = cost + grid[x + 1][y];
                pq.push({dist[x + 1][y][remainingTeleport],
                         {remainingTeleport, {x + 1, y}}});
            }

            // Teleport
            if (remainingTeleport > 0)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (!(i == x && j == y) && grid[i][j] <= grid[x][y] &&
                            dist[i][j][remainingTeleport - 1] > cost)
                        {

                            dist[i][j][remainingTeleport - 1] = cost;
                            pq.push({cost, {remainingTeleport - 1, {i, j}}});
                        }
                    }
                }
            }
        }

        return -1;
    }
};

// the optimal solution

class Solution
{
public:
    int minCost(vector<vector<int>> &grid, int k)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> cost(n, vector<int>(m, 1e9));

        vector<pair<int, int>> cells;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cells.push_back({i, j});
            }
        }

        sort(cells.begin(), cells.end(),
             [&](auto a, auto b)
             {
                 return grid[a.first][a.second] <
                        grid[b.first][b.second];
             });

        for (int step = 0; step <= k; step++)
        {

            int best = 1e9;

            for (int idx = 0; idx < cells.size(); idx++)
            {
                int r = cells[idx].first;
                int c = cells[idx].second;

                best = min(best, cost[r][c]);

                if (idx + 1 < cells.size() &&
                    grid[r][c] ==
                        grid[cells[idx + 1].first][cells[idx + 1].second])
                {
                    continue;
                }

                int back = idx;
                while (back >= 0 &&
                       grid[cells[back].first][cells[back].second] == grid[r][c])
                {
                    cost[cells[back].first][cells[back].second] = best;
                    back--;
                }
            }

            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = m - 1; j >= 0; j--)
                {

                    if (i == n - 1 && j == m - 1)
                    {
                        cost[i][j] = 0;
                        continue;
                    }

                    if (i + 1 < n)
                        cost[i][j] = min(cost[i][j],
                                         cost[i + 1][j] + grid[i + 1][j]);

                    if (j + 1 < m)
                        cost[i][j] = min(cost[i][j],
                                         cost[i][j + 1] + grid[i][j + 1]);
                }
            }
        }

        return cost[0][0];
    }
};