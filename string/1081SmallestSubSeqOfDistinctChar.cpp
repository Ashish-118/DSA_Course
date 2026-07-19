class Solution
{
public:
    string smallestSubsequence(string s)
    {
        unordered_set<int> distinct;
        for (auto x : s)
            distinct.insert(x - 'a');

        int len = distinct.size();
        int n = s.length();

        string ans = "";

        unordered_set<int> elements;

        vector<bool> visited(26, false);

        int idx = -1;

        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < 26; j++)
            {

                if (visited[j] || distinct.find(j) == distinct.end())
                    continue;

                unordered_set<int> avail;

                bool found = false;
                int foundIdx = -1;

                for (int x = idx + 1; x < n; x++)
                {

                    if (!found && s[x] == (j + 'a'))
                    {
                        found = true;
                        foundIdx = x;
                    }

                    if (found && elements.find(s[x] - 'a') == elements.end())
                    {
                        avail.insert(s[x] - 'a');
                    }
                }

                if ((len - ans.length()) == avail.size())
                {
                    ans = ans + string(1, j + 'a');
                    elements.insert(j);
                    idx = foundIdx;

                    visited[j] = true;

                    break;
                }
            }
        }

        return ans;
    }
};