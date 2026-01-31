class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {

        // a = "abcd"
        // b = "cdabcdab"

        // b can be formed in following ways:
        //
        // b = prefix + n*a + suffix   -> need n + 2 repeats
        // b = prefix + n*a            -> need n + 1 repeats
        // b = n*a + suffix            -> need n + 1 repeats
        // b = n*a                     -> need n repeats

        int len_a = a.length();
        int len_b = b.length();

        // Minimum repeats needed so that repeated length >= b
        int n = len_b / len_a;
        int cnt = n;

        string na = "";

        // repeat a exactly n times
        while (cnt--)
        {
            na = na + a;
        }

        // Case: b is substring of n*a
        if (na.find(b) != string::npos)
        {
            return n;
        }

        // Case: b is substring of (n+1)*a
        na = na + a;
        if (na.find(b) != string::npos)
        {
            return n + 1;
        }

        // Case: b is substring of (n+2)*a
        na = na + a;
        if (na.find(b) != string::npos)
        {
            return n + 2;
        }

        // Not possible
        return -1;
    }
};

// best optimal approach using KMP algorithm

class Solution
{
public:
    vector<int> LPS;

    void computeLPS(string pattern)
    {
        LPS[0] = 0;
        int maxLPS_len = 0;
        int i = 1;
        int n = pattern.length();

        while (i < n)
        {
            if (pattern[maxLPS_len] == pattern[i])
            {
                maxLPS_len++;
                LPS[i] = maxLPS_len;
                i++;
            }
            else
            {

                if (maxLPS_len == 0)
                {
                    LPS[i] = 0;
                    i++;
                }
                else
                    maxLPS_len = LPS[maxLPS_len - 1];
            }
        }
    }
    bool kmp(string s, string pattern)
    {
        LPS = vector<int>(pattern.length(), 0);
        computeLPS(pattern);
        int l1 = s.length(), l2 = pattern.length();

        int i = 0, j = 0;

        while (i < l1)
        {

            if (pattern[j] == s[i])
            {
                j++;
                i++;
            }
            else
            {
                if (j != 0)
                    j = LPS[j - 1];

                else
                    i++;
            }

            if (j == l2)
            {
                return true;
            }
        }

        return false;
    }
    int repeatedStringMatch(string a, string b)
    {

        // a = "abcd"
        // b = "cdabcdab"

        // b can be formed in following ways:
        //
        // b = prefix + n*a + suffix   -> need n + 2 repeats
        // b = prefix + n*a            -> need n + 1 repeats
        // b = n*a + suffix            -> need n + 1 repeats
        // b = n*a                     -> need n repeats

        int len_a = a.length();
        int len_b = b.length();

        int n = len_b / len_a;
        int cnt = n;

        string na = "";

        // repeat a exactly n times
        while (cnt--)
        {
            na = na + a;
        }

        // Case: b is substring of n*a
        if (kmp(na, b))
        {
            return n;
        }

        // Case: b is substring of (n+1)*a
        na = na + a;
        if (kmp(na, b))
        {
            return n + 1;
        }

        // Case: b is substring of (n+2)*a
        na = na + a;
        if (kmp(na, b))
        {
            return n + 2;
        }

        // Not possible
        return -1;
    }
};
