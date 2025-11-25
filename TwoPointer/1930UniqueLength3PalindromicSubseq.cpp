class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {

        int n = s.length();
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            unordered_map<char, int> mp;
            char c = 'a' + i;
            for (int j = 0; j < n; j++)
            {
                mp[s[j]]++;
            }

            int start = 0, end = n - 1;

            while (end - start + 1 > 3)
            {
                if (s[start] != c)
                {
                    mp[s[start]]--;

                    if (mp[s[start]] == 0)
                        mp.erase(s[start]);

                    start++;
                }
                if (s[end] != c)
                {
                    mp[s[end]]--;

                    if (mp[s[end]] == 0)
                        mp.erase(s[end]);
                    end--;
                }

                if (s[start] == c && s[end] == c)
                    break;
            }
            if (s[start] == c && s[end] == c)
            {
                mp[s[start]]--;

                if (mp[s[start]] == 0)
                    mp.erase(s[start]);
                mp[s[end]]--;

                if (mp[s[end]] == 0)
                    mp.erase(s[end]);
                ans += (int)mp.size();
            }
        }

        return ans;
    }
};