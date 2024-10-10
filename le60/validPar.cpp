class Solution
{
public:
    bool isValid(string s1)
    {
        stack<char> s;
        for (int i = 0; i < s1.length(); i++)
        {
            char ch = s1[i];

            if (ch == '(' || ch == '{' || ch == '[')
            {
                s.push(ch);
            }
            else
            {
                // for closing
                if (!s.empty())
                {
                    char top = s.top();
                    if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                    {
                        s.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};