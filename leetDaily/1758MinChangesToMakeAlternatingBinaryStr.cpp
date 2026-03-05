class Solution
{
public:
    int minOperations(string s)
    {

        function<int(char)> solve = [&](char start)
        {
            int ops = 0;
            for (int i = 0; i < s.length(); i++)
            {
                if (start == '0')
                {
                    if (start != s[i])
                    {
                        ops++;
                    }
                    start = '1';
                }
                else
                {
                    if (start != s[i])
                    {
                        ops++;
                    }
                    start = '0';
                }
            }
            return ops;
        };
        int ans1 = solve('0');
        int ans2 = solve('1');

        return min(ans1, ans2);
    }
};