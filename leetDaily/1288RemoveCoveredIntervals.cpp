class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        vector<vector<int>> temp;

        sort(begin(intervals), end(intervals));
        temp.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {

            if (intervals[i][0] == temp.back()[0])
            {

                temp.pop_back();
                temp.push_back(intervals[i]);
            }
            else if (intervals[i][0] > temp.back()[0] &&
                     intervals[i][1] <= temp.back()[1])
            {
            }
            else
            {
                temp.push_back(intervals[i]);
            }
        }

        return temp.size();
    }
};