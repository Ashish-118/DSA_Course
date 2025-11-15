class Solution
{
public:
    string customSortString(string order, string s)
    {
        unordered_map<char, int> freq;
        for (auto &x : s)
        {
            freq[x]++;
        }

        string ans = "";

        for (auto c : order)
        {
            while (freq[c])
            {
                ans += c;
                freq[c]--;
            }
        }

        for (auto &m : freq)
        {
            while (freq[m.first])
            {
                ans += m.first;
                freq[m.first]--;
            }
        }

        return ans;
    }
};