class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> mp;

        for (auto x : words)
        {

            mp[x]++;
        }

        int len = 0;

        for (auto m : mp)
        {
            string s = m.first;
            string rev = {s[1], s[0]};
            if (s[0] == s[1])
            {

                if (mp[s] >= 2)
                {
                    len += ((mp[s] / 2) * 4);
                    mp[s] -= ((mp[s] / 2) * 2);
                }
            }
            else if (mp.count(rev))
            {
                int mini = min(mp[rev], mp[s]);
                len += (mini * 2 * 2);
                mp[rev] -= mini;
                mp[s] -= mini;
            }
        }

        for (auto m : mp)
        {
            if (m.second == 1 && m.first[0] == m.first[1])
            {
                len += 2;
                break;
            }
        }

        return len;
    }
};