class Solution
{
public:
    int minAddToMakeValid(string s)
    {

        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (!st.empty())
            {
                char top = st.top();
                if (top == '(' && s[i] == ')')
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }

        int len = 0;
        while (!st.empty())
        {
            len++;
            st.pop();
        }
        return len;
    }
}; // used stack to keep track of the parentheses

// without stack but same logic

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int openBrackets = 0;

        int minAddsRequired = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                openBrackets++;
            }
            else
            {
                openBrackets > 0 ? openBrackets-- : minAddsRequired++;
            }
        }

        return minAddsRequired + openBrackets;
    }
};