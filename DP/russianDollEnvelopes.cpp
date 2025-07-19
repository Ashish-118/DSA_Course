class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] > b[1]; // sort by width ascending, height descending
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), cmp);
        int n = envelopes.size();
        if (n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(envelopes[0][1]);

        for (int i = 1; i < n; i++)
        {
            int h = envelopes[i][1];
            if (ans.back() < h)
            {
                ans.push_back(h);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), h) - ans.begin();
                ans[index] = h;
            }
        }

        return ans.size();
    }
};
/// using longest increasing subsequence (LIS) approach
/// Time Complexity: O(n log n), where n is the number of envelopes.
/// Space Complexity: O(n) for the ans vector.