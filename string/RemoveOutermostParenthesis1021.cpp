class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int open = 0, close = 0;
        int n = s.length();
        string ans = "";
        bool check = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                open++;
            if (s[i] == ')')
                close++;

            if (open == close)
            {
                open = 0;
                close = 0;
                check = false;
            }
            else if (check)
            {
                ans.push_back(s[i]);
            }
            else
            {
                check = true;
            }
        }
        return ans;
    }
};