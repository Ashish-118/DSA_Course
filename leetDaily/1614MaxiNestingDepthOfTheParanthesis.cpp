class Solution
{
public:
    int maxDepth(string s)
    {

        int n = s.length();
        int open = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                open++;
            }
            else if (s[i] == ')')
            {
                open--;
            }

            ans = max(ans, open);
        }

        return ans;
    }
};