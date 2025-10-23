class Solution
{
public:
    using pp = pair<int, int>;
    vector<int> avoidFlood(vector<int> &rains)
    {
        unordered_map<int, set<int>> mp;
        int n = rains.size();

        unordered_map<int, bool> filled;

        priority_queue<pp, vector<pp>, greater<pp>> pq;

        for (int i = 0; i < n; i++)
        {
            if (rains[i] == 0)
                continue;
            mp[rains[i]].insert(i);
            filled[rains[i]] = false;
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (rains[i] > 0)
            {
                if (filled[rains[i]])
                    return {};
                ans[i] = -1;
                filled[rains[i]] = true;
                mp[rains[i]].erase(mp[rains[i]].begin());
                if (!mp[rains[i]].empty())
                {
                    pq.push({*mp[rains[i]].begin(), rains[i]});
                }
            }
            else
            {
                if (!pq.empty())
                {
                    pp top_element = pq.top();
                    ans[i] = top_element.second;
                    pq.pop();
                    filled[top_element.second] = false;
                }
                else
                {
                    ans[i] = 1;
                }
            }
        }
        return ans;
    }
}; // tc: O(nlogn) sc: O(n)