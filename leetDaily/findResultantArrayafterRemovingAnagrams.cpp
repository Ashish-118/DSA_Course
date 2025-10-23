class Solution
{
public:
    bool poss(string s1, string s2)
    {
        if (s1.length() != s2.length())
            return false;

        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        for (int i = 0; i < s1.length(); i++)
        {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }

        for (int i = 0; i < s1.length(); i++)
        {
            if (m1[s1[i]] != m2[s1[i]])
                return false;
        }

        return true;
    }
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> ans;
        ans.push_back(words[0]);
        int n = words.size();

        for (int i = 1; i < n; i++)
        {
            if (!poss(words[i], ans.back()))
            {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};