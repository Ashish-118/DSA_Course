class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        vector<pair<int, int>> events;

        for (auto log : logs)
        {

            events.push_back({log[0], +1});
            events.push_back({log[1], -1});
        }

        sort(begin(events), end(events));

        int currPop = 0, maxPop = 0, year = 0;

        for (auto x : events)
        {

            currPop += x.second;
            if (currPop > maxPop)
                year = x.first;
            maxPop = max(maxPop, currPop);
        }

        return year;
    }
};