class Solution
{
public:
    int countBinarySubstrings(string s)
    {

        int ans = 0;

        char start = s[0];
        int zero = 0, one = 0;

        for (int i = 0; i < s.length(); i++)
        {

            if (start == s[i] && zero != 0 && one != 0)
            {
                ans += min(zero, one);

                if (start == '0')
                {
                    zero = 0;
                    start = '1';
                }
                else
                {
                    one = 0;
                    start = '0';
                }
            }

            if (s[i] == '0')
                zero++;
            if (s[i] == '1')
                one++;
        }

        ans += min(zero, one);
        return ans;
    }
};