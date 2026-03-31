

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {

        unordered_map<pair<int, int>, set<pair<int, int>>,
                      function<size_t(pair<int, int>)>>
            slopes(0, [](const pair<int, int> &p)
                   { return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1); });

        int n = points.size();
        if (n == 1)
            return 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                int x = points[i][0], y = points[i][1];
                int x1 = points[j][0], y1 = points[j][1];

                int dy = y1 - y;
                int dx = x1 - x;

                if (dx == 0)
                {
                    slopes[{1, 0}].insert({x, y}); // vertical
                }
                else if (dy == 0)
                {
                    slopes[{0, 1}].insert({x, y}); // horizontal
                }
                else
                {
                    int g = gcd(dy, dx);
                    dy /= g;
                    dx /= g;

                    // normalize sign
                    if (dx < 0)
                    {
                        dx *= -1;
                        dy *= -1;
                    }

                    slopes[{dy, dx}].insert({x, y});
                }
            }
        }

        int ans = 0;

        for (auto &x : slopes)
        {
            unordered_map<long long, int> intercept;
            int dy = x.first.first, dx = x.first.second;

            int maxi = 0;

            if (dx == 0)
            {
                // vertical → x = constant
                for (auto &p : x.second)
                {
                    intercept[p.first]++;
                    maxi = max(maxi, intercept[p.first]);
                }
            }
            else
            {
                for (auto &p : x.second)
                {
                    // c = y*dx - dy*x (avoid floating)
                    long long c = 1LL * p.second * dx - 1LL * dy * p.first;

                    intercept[c]++;
                    maxi = max(maxi, intercept[c]);
                }
            }

            ans = max(ans, maxi);
        }

        return ans;
    }
};

// optimal appraoch

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {

        int n = points.size();
        if (n <= 2)
            return n;

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_map<double, int> mp;
            int maxi = 0;

            int x = points[i][0], y = points[i][1];

            for (int j = i + 1; j < n; j++)
            {
                int x1 = points[j][0], y1 = points[j][1];

                if (x1 == x)
                {
                    mp[INT_MAX]++; // vertical line
                    maxi = max(maxi, mp[INT_MAX]);
                }
                else
                {
                    double slope = (double)(y1 - y) / (x1 - x);
                    mp[slope]++;
                    maxi = max(maxi, mp[slope]);
                }
            }

            ans = max(ans, maxi + 1);
        }

        return ans;
    }
};