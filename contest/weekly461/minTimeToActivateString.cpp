class Solution
{
public:
    int minTime(string s, vector<int> &order, int k)
    {
        int n = s.length(), m = order.size();
        set<int> pos = {-1, n};
        for (int t = 0; t < m; ++t)
        {
            int i = order[t];
            auto it = pos.lower_bound(i);
            int r = *it, l = *(--it);
            k -= (long long)(i - l) * (r - i);
            pos.insert(i);
            if (k <= 0)
            {
                return t;
            }
        }
        return -1;
    }
};