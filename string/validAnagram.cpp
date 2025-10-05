class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        int n = s.length();
        int m = t.length();

        if (n != m)
            return false;

        set<char> st;
        for (int i = 0; i < n; i++)
        {
            m1[s[i]]++;
            m2[t[i]]++;
            st.insert(s[i]);
        }

        for (auto &x : st)
        {
            if (m2.count(x) == 0 || m1[x] != m2[x])
                return false;
        }

        return true;
    }
};