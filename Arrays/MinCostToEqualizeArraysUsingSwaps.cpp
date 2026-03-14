class Solution
{
public:
    int minCost(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();

        unordered_map<int, int> mp;
        for (auto x : nums1)
            mp[x]++;
        for (auto x : nums2)
            mp[x]++;

        for (auto x : mp)
        {
            if (x.second & 1)
                return -1;
        }

        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        set<pair<int, int>, greater<pair<int, int>>> st;

        for (auto x : nums1)
        {

            mp1[x]++;
        }
        for (auto x : nums2)
        {
            mp2[x]++;
        }

        for (auto x : mp)
        {
            st.insert({abs(mp1[x.first] - mp2[x.first]), x.first});
        }
        int bad = 0;
        int ans = 0;

        for (auto x : st)
        {

            if (mp1[x.second] != mp2[x.second])
            {
                int b = (((mp1[x.second] + mp2[x.second]) / 2) -
                         min(mp1[x.second], mp2[x.second]));
                if (bad != 0)
                    ans += min(bad, b);
                bad = abs(bad - b);
            }
        }

        return ans;
    }
};
©leetcode