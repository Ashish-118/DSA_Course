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