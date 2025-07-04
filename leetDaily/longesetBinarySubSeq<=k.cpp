class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        string newStr1 = "";
        int len = s.length();

        int exp = len - 1;
        for (int i = 0; i < len; i++)
        {
            if ((pow(2, exp - i) * stoi(string(1, s[i]))) <= k)
            {
                newStr1 += s[i];
            }
        }

        string newStr2 = "";
        int sum = 0;
        exp = 0;

        for (int i = newStr1.length() - 1; i >= 0; i--)
        {
            int add = (pow(2, exp) * stoi(string(1, newStr1[i])));

            if ((sum + add) <= k)
            {
                sum += add;
                newStr2 += newStr1[i];
            }

            exp++;
        }

        return newStr2.length();
    }
}; //

/// more optimised code

class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        int sm = 0;
        int cnt = 0;
        int bits = 32 - __builtin_clz(k);
        for (int i = 0; i < s.size(); ++i)
        {
            char ch = s[s.size() - 1 - i];
            if (ch == '1')
            {
                if (i < bits && sm + (1 << i) <= k)
                {
                    sm += 1 << i;
                    cnt++;
                }
            }
            else
            {
                cnt++;
            }
        }
        return cnt;
    }
};