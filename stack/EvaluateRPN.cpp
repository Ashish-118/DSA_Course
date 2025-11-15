class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++)
        {

            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/" &&
                tokens[i] != "*")
            {
                st.push(stoi(tokens[i]));
            }
            else
            {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();

                if (tokens[i] == "+")
                    st.push(n2 + n1);
                else if (tokens[i] == "-")
                    st.push(n2 - n1);
                else if (tokens[i] == "/")
                    st.push(n2 / n1);
                else
                    st.push(n2 * n1);
            }
        }

        return st.top();
    }
};