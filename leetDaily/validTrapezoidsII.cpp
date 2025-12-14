class Solution
{
public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        unordered_map<double, vector<vector<int>>> mp;
        int n = points.size();

        for (int i = 0; i < n; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];

                double denominator = x2 - x1;
                double numerator = y2 - y1;

                if (denominator == 0)
                {

                    mp[INT_MAX].push_back({x1, y1, x2, y2});

                    continue;
                }

                mp[(numerator / denominator)].push_back({x1, y1, x2, y2});
            }
        }

        int ans = 0;

        for (auto m : mp)
        {

            int len = m.second.size();
            for (int i = 0; i < len; i++)
            {
                int x1 = m.second[i][0];
                int y1 = m.second[i][1];
                for (int j = i + 1; j < len; j++)
                {
                    int x = m.second[j][0];
                    int y = m.second[j][1];
                    if (m.first == 0 && y1 != y)
                    {

                        ans++;
                    }
                    else if (m.first == INT_MAX && x1 != x)
                    {

                        ans++;
                    }
                    else if (m.first != 0 && m.first != INT_MAX &&
                             y != (m.first * x - m.first * x1 - y1))
                    {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};