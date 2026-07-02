class Solution
{
public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int m = grid.size(), n = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        int initialCost = (grid[0][0] ? 1 : 0);
        pq.push({initialCost, 0, 0});
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        dist[0][0] = initialCost;
        int mini = -1;

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int i = top[1], j = top[2], cost = top[0];
            if (dist[i][j] < cost)
                continue;

            if (i == m - 1 && j == n - 1)
            {
                mini = cost;
                break;
            }
            for (auto d : dir)
            {
                int x_ = i + d.first;
                int y_ = j + d.second;

                if (x_ >= m || y_ >= n || x_ < 0 || y_ < 0)
                    continue;
                int w = (grid[x_][y_] ? 1 : 0);
                if (dist[x_][y_] > cost + w)
                {
                    dist[x_][y_] = cost + w;
                    pq.push({cost + w, x_, y_});
                }
            }
        }

        return health - mini >= 1;
    }
};