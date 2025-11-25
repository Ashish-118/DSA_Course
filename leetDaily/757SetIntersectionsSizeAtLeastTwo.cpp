class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        // Sort by (right, left)
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });

        int res = 0;
        int p1 = -1, p2 = -1; // last two chosen points

        for (auto &in : intervals)
        {
            int left = in[0];
            int right = in[1];

            // Case 1: no overlap with last two points
            if (p2 < left)
            {
                res += 2;
                p1 = right - 1;
                p2 = right;
            }
            // Case 2: only one of the points overlaps
            else if (p1 < left)
            {
                res += 1;
                // If p2 == right, shift one back
                if (p2 == right)
                {
                    p1 = right - 1;
                }
                else
                {
                    p1 = p2;
                    p2 = right;
                }
            }
            // Case 3: both points already inside → do nothing
        }

        return res;
    }
};
