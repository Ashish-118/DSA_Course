class Solution
{
public:
    vector<vector<long long>> splitPainting(vector<vector<int>> &segments)
    {
        vector<pair<pair<int, int>, int>> events;
        // 0->end
        //  1->start
        for (auto s : segments)
        {
            events.push_back({{s[0], 1}, s[2]});
            events.push_back({{s[1], 0}, -s[2]});
        }

        sort(begin(events), end(events));

        int s = -1;
        long long windowMix = 0;
        vector<vector<long long>> ans;

        for (int i = 0; i < events.size(); i++)
        {
            int d = events[i].first.first;
            int type = events[i].first.second;
            int val = events[i].second;
            if (type == 1)
            {
                if (s == -1)
                {
                    s = d;
                }
                else
                {
                    if (d - s != 0 && windowMix)
                    {
                        ans.push_back({s, d, windowMix});
                    }
                }
                windowMix += val;
                s = d;
            }
            else
            {

                if (s != -1 && d - s != 0 && windowMix)
                {
                    ans.push_back({s, d, windowMix});
                }
                windowMix += val;
                s = d;
            }
        }

        return ans;
    }
};