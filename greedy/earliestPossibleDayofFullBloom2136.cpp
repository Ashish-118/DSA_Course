class Solution
{
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        int bloomDay = 0;
        vector<pair<int, int>> grow;
        for (int i = 0; i < growTime.size(); i++)
        {
            grow.push_back({growTime[i], i});
        }
        int day = 0;

        sort(begin(grow), end(grow), [&](pair<int, int> &a, pair<int, int> &b)
             { return a.first > b.first; });

        for (auto x : grow)
        {
            int i = x.second;

            day += plantTime[i];
            bloomDay = max(bloomDay, day + x.first);
        }

        return bloomDay;
    }
};