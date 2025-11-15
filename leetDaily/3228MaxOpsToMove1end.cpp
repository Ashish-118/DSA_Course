class Solution
{
public:
    int maxOperations(string s)
    {
        int count = 0;
        int ans = 0;
        int ones = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0' && count != 0)
            {
                ones += count;
                ans += (ones);
                count = 0;
            }
            if (s[i] == '1')
            {
                count++;
            }
        }

        return ans;
    }
};