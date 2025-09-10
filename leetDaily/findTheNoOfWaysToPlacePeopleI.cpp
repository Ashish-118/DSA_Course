class Solution
{
public:
    int numberOfPairs(vector<vector<int>> &points)
    {
        int n = points.size();
        int count = 0;

        sort(begin(points), end(points), [](const vector<int> &a, const vector<int> &b)
             {
                 if (a[0] == b[0])
                     return a[1] > b[1]; // second descending
                 return a[0] < b[0];     // first ascending
             });

        for (auto &x : points)
        {
            cout << x[0] << " " << x[1] << endl;
        }

        for (int l = 0; l < n; l++)
        {
            int x1 = points[l][0], y1 = points[l][1];

            for (int x = l + 1; x < n; x++)
            {
                int x2 = points[x][0], y2 = points[x][1];
                bool check = false;
                if (x1 == x2 && y1 > y2)
                {
                    check = true;
                    for (int i = l + 1; i < x; i++)
                    {
                        if ((x1 <= points[i][0] && points[i][0] <= x2 && points[i][1] >= y2 && points[i][1] <= y1))
                        {
                            check = false;
                            break;
                        }
                    }
                }
                else if (x1 < x2 && y1 >= y2)
                {
                    check = true;
                    for (int i = l + 1; i < x; i++)
                    {
                        if ((x1 <= points[i][0] && points[i][0] <= x2 && points[i][1] >= y2 && points[i][1] <= y1))
                        {
                            check = false;
                            break;
                        }
                    }
                }

                if (check)
                    count++;
            }
        }

        return count;
    }
}; // O(n^3) T.c

// more optimal solution Brute force

class Solution
{
public:
    int numberOfPairs(vector<vector<int>> &points)
    {
        int n = points.size();
        int result = 0;

        for (int i = 0; i < n; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1]; // candidate for upper-left

            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                int x2 = points[j][0];
                int y2 = points[j][1]; // candidate for lower-right

                // Condition: (x1, y1) must be upper-left of (x2, y2)
                if (x1 <= x2 && y1 >= y2)
                {
                    bool hasPointInside = false;

                    // Check if some point lies inside or on the rectangle
                    for (int k = 0; k < n; k++)
                    {
                        if (k == i || k == j)
                            continue;

                        int x3 = points[k][0];
                        int y3 = points[k][1];

                        if (x3 >= x1 && x3 <= x2 &&
                            y3 <= y1 && y3 >= y2)
                        {
                            hasPointInside = true;
                            break;
                        }
                    }

                    if (!hasPointInside)
                    {
                        result++;
                    }
                }
            }
        }

        return result;
    }
};

// best solutiong using  sorting O(n^2) T.c and O(1) S.c

// Approach-2 (Using Sorting)
// T.C : O(n^2)
// S.C : O(1)
class Solution
{
public:
    int numberOfPairs(vector<vector<int>> &points)
    {
        int n = points.size();

        // Sort: x ascending, if x same then sort as y descending
        auto lambda = [](vector<int> &point1, vector<int> &point2)
        {
            if (point1[0] == point2[0])
            {
                return point1[1] > point2[1];
            }
            return point1[0] < point2[0];
        };

        sort(points.begin(), points.end(), lambda);

        int result = 0;

        for (int i = 0; i < n; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1]; // upper left

            int bestY = INT_MIN;

            for (int j = i + 1; j < n; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1]; // lower right

                // Condition: (x2, y2) must be above (x1, y1)
                if (y2 > y1)
                { // not lower right
                    continue;
                }

                if (y2 > bestY)
                {
                    result++;
                    bestY = y2;
                }
            }
        }

        return result;
    }
};
