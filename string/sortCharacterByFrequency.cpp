class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        for (auto &x : s)
            mp[x]++;
        set<pair<int, char>> st;

        for (auto &m : mp)
        {
            st.insert({-m.second, m.first});
        }

        s = "";

        for (auto &x : st)
        {
            s += string(-x.first, x.second);
        }

        return s;
    }
};