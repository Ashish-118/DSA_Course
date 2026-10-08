class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ans = "";

        int idx = 0;
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            count += (s[i] == '(' ? 1 : -1);

            if (count == 0)
            {
                ans += s.substr(idx + 1, i - idx - 1);
                idx = i + 1;
            }
        }

        return ans;
    }
};