class Solution
{
public:
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        vector<pair<int, int>> dur;
        for (int i = 0; i < start.size(); i++)
        {
            dur.push_back({start[i], end[i]});
        }

        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.second < b.second;
        };
        sort(dur.begin(), dur.end(), cmp);

        int endTime = -1;
        int count = 0;
        for (auto &x : dur)
        {
            if (x.first > endTime)
            {
                endTime = x.second;
                count++;
            }
        }
        return count;
    }
};
