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
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> points;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                points.push_back({i, j});
            }
        }
        sort(points.begin(), points.end(),
             [&](const auto &p1, const auto &p2) -> bool
             {
                 return grid[p1.first][p1.second] < grid[p2.first][p2.second];
             });
        vector<vector<int>> costs(m, vector<int>(n, INT_MAX));
        for (int t = 0; t <= k; t++)
        {
            int minCost = INT_MAX;
            for (int i = 0, j = 0; i < points.size(); i++)
            {
                minCost =
                    min(minCost, costs[points[i].first][points[i].second]);
                if (i + 1 < points.size() &&
                    grid[points[i].first][points[i].second] ==
                        grid[points[i + 1].first][points[i + 1].second])
                {
                    continue;
                }
                for (int r = j; r <= i; r++)
                {
                    costs[points[r].first][points[r].second] = minCost;
                }
                j = i + 1;
            }
            for (int i = m - 1; i >= 0; i--)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    if (i == m - 1 && j == n - 1)
                    {
                        costs[i][j] = 0;
                        continue;
                    }
                    if (i != m - 1)
                    {
                        costs[i][j] =
                            min(costs[i][j], costs[i + 1][j] + grid[i + 1][j]);
                    }
                    if (j != n - 1)
                    {
                        costs[i][j] =
                            min(costs[i][j], costs[i][j + 1] + grid[i][j + 1]);
                    }
                }
            }
        }
        return costs[0][0];
    }
};
