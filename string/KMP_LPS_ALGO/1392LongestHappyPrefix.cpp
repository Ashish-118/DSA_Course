class Solution
{
public:
    string longestPrefix(string s)
    {
        int n = s.length();
        vector<int> LPS(n, 0);

        int i = 1;
        int maxLpsLen = 0;

        while (i < n)
        {
            if (s[maxLpsLen] == s[i])
            {
                maxLpsLen++;
                LPS[i] = maxLpsLen;

                i++;
            }
            else
            {
                if (maxLpsLen == 0)
                {
                    LPS[i] = 0;
                    i++;
                }
                else
                {
                    maxLpsLen = LPS[maxLpsLen - 1];
                }
            }
        }

        return s.substr(0, LPS[n - 1]);
    }
};
// Time Complexity: O(N)
// Space Complexity: O(N)