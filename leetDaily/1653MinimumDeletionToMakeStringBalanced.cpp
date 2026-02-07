class Solution
{
public:
    int minimumDeletions(string s)
    {
        stack<char> st;

        int n = s.length();
        int count = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (!st.empty() && s[i] == 'b' && st.top() == 'a')
            {
                st.pop();
                count++;
            }
            else
                st.push(s[i]);
        }

        return count;
    }
};