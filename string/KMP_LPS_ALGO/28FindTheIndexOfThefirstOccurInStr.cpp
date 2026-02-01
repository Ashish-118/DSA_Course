class Solution
{
public:
    vector<int> LPS;

    void computeLPS(string s, string pattern)
    {
        LPS[0] = 0;

        int maxLpsLen = 0;
        int i = 1;
        while (i < pattern.length())
        {
            if (pattern[maxLpsLen] == pattern[i])
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
    }

    int kmp(string s, string pattern)
    {
        int j = 0;
        int i = 0;

        while (i < s.length())
        {

            if (pattern[j] == s[i])
            {
                j++;
                i++;
            }
            else
            {
                if (j != 0)
                {
                    j = LPS[j - 1];
                }
                else
                {
                    i++;
                }
            }

            if (j == pattern.length())
            {
                return i - j;
            }
        }

        return -1;
    }

    int strStr(string haystack, string needle)
    {
        int n = needle.length();
        LPS = vector<int>(n, 0);

        computeLPS(haystack, needle);

        return kmp(haystack, needle);
    }
};