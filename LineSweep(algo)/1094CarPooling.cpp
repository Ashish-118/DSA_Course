class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        vector<pair<int, int>> events;
        for (auto trip : trips)
        {
            events.push_back({trip[1], trip[0]});
            events.push_back({trip[2], -trip[0]});
        }

        sort(begin(events), end(events));

        int curr = 0;

        for (auto event : events)
        {
            curr += event.second;
            if (curr > capacity)
                return false;
        }

        return true;
    }
};