class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(begin(intervals), end(intervals), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        int top = INT_MIN, count = 0;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (top > intervals[i][0])
            {
                count++;
            }
            else
            {
                top = intervals[i][1];
            }
        }
        return count;
    }
};