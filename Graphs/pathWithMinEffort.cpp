class Solution
{
public:
    typedef pair<int, pair<int, int>> P;
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});

        result[0][0] = 0;

        auto isSafe = [&](int x, int y)
        {
            return x >= 0 && x < m && y >= 0 && y < n;
        };

        while (!pq.empty())
        {
            int diff = pq.top().first;
            auto cordination = pq.top().second;
            pq.pop();

            int x = cordination.first;
            int y = cordination.second;

            for (auto d : dir)
            {
                int x_ = x + d[0];
                int y_ = y + d[1];
                if (isSafe(x_, y_))
                {
                    int absDiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxDiff = max(diff, absDiff);
                    if (result[x_][y_] > maxDiff)
                    {
                        result[x_][y_] = maxDiff;
                        pq.push({maxDiff, {x_, y_}});
                    }
                }
            }
        }

        return result[m - 1][n - 1];
    }
};