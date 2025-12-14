class Solution
{
public:
    bool valid(int i, int j, int row, int col)
    {
        if (i < 0 || i > (row - 1))
            return false;
        else if (j < 0 || j > (col - 1))
            return false;

        return true;
    }
    int dij(vector<vector<int>> &grid, vector<vector<int>> &dist, int row, int col)
    {

        vector<pair<int, int>> dr = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
        set<pair<int, pair<int, int>>> minSet;

        if (grid[0][0] == 0)
        {
            minSet.insert({1, {0, 0}});
            dist[0][0] = 1;
        }
        else
        {
            minSet.insert({INT_MAX, {0, 0}});
            dist[0][0] = INT_MAX;
        }

        while (!minSet.empty())
        {
            auto top = *(minSet.begin());
            pair<int, int> loc = top.second;
            int i = loc.first;
            int j = loc.second;
            minSet.erase(minSet.begin());
            int distance = top.first;

            if (grid[i][j] == 0)
            {

                for (auto dir : dr)
                {
                    int r = i + dir.first, c = j + dir.second;

                    if (valid(r, c, row, col) && grid[r][c] == 0 && dist[r][c] > (distance + 1))
                    {

                        auto present = minSet.find({dist[r][c], {r, c}});
                        dist[r][c] = dist[i][j] + 1;
                        if (present != minSet.end())
                        {
                            minSet.erase(present);
                        }
                        minSet.insert({dist[r][c], {r, c}});
                    }
                }
            }
        }

        return (dist[row - 1][col - 1] != INT_MAX ? dist[row - 1][col - 1] : -1);
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));

        return dij(grid, dist, row, col);
    }
};

// we can also solve using minheap and without dist array

class Solution
{
public:
    using p = pair<int, pair<int, int>>;

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        vector<pair<int, int>> dir = {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        priority_queue<p, vector<p>, greater<p>> pq;
        int n = grid.size();

        auto valid = [&](int i, int j)
        {
            if (i >= 0 && j >= 0 && j < n && i < n && grid[i][j] == 0)
            {
                return true;
            }
            return false;
        };

        if (grid[0][0] == 0)
        {
            pq.push({1, {0, 0}});
        }
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        while (!pq.empty())
        {
            int w = pq.top().first;

            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == n - 1 && y == n - 1)
                return w;

            if (visited[x][y])
                continue; // stale entry

            visited[x][y] = true;

            for (auto d : dir)
            {
                int x_ = x + d.first;
                int y_ = y + d.second;
                if (valid(x_, y_))
                {
                    pq.push({w + 1, {x_, y_}});
                }
            }
        }

        return -1;
    }
};

// optimal approach--   use BFS since all edges have same weight

class Solution
{
public:
    using p = pair<int, pair<int, int>>;

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        vector<pair<int, int>> dir = {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        queue<p> pq;
        int n = grid.size();

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        auto valid = [&](int i, int j)
        {
            if (i >= 0 && j >= 0 && j < n && i < n && grid[i][j] == 0 && !visited[i][j])
            {
                return true;
            }
            return false;
        };

        if (grid[0][0] == 0)
        {
            pq.push({1, {0, 0}});
        }

        while (!pq.empty())
        {
            int w = pq.front().first;

            int x = pq.front().second.first;
            int y = pq.front().second.second;
            pq.pop();

            if (x == n - 1 && y == n - 1)
                return w;

            for (auto d : dir)
            {
                int x_ = x + d.first;
                int y_ = y + d.second;
                if (valid(x_, y_))
                {
                    pq.push({w + 1, {x_, y_}});
                    visited[x_][y_] = true;
                }
            }
        }

        return -1;
    }
};