class Solution
{
public:
    string shortestPalindrome(string s)
    {
        string rev = s;
        reverse(begin(rev), end(rev));

        // T.C : O(n^2)
        // S.C : O(n)
        for (int i = 0; i < s.length(); i++)
        {
            // prefix in s == suffix in rev
            if (!memcmp(s.c_str(), rev.c_str() + i, s.length() - i))
            {
                return rev.substr(0, i) + s;
            }
        }

        return rev + s;
    }
};

// the most optimal approach using KMP LPS array

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        if (s.empty())
            return "";

        string rev = s;
        reverse(begin(rev), end(rev));

        string newStr = s + "-" + rev;
        int n = newStr.length();
        vector<int> LPS(n, 0);

        int j = 1;
        int maxLpsLen = 0;

        while (j < n)
        {
            if (newStr[maxLpsLen] == newStr[j])
            {
                maxLpsLen++;
                LPS[j] = maxLpsLen;
                j++;
            }
            else
            {
                if (maxLpsLen == 0)
                {
                    LPS[j] = 0;
                    j++;
                }
                else
                {
                    maxLpsLen = LPS[maxLpsLen - 1];
                }
            }
        }

        return rev.substr(0, rev.length() - LPS[n - 1]) + s;
    }
};
