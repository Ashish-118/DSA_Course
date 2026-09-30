class Solution
{
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        stack<int> st;
        int n = seq.length();

        int seqA_B = 1;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (seq[i] == '(')
            {
                seqA_B = !seqA_B;
                st.push(i);
            }
            else
            {
                ans[i] = seqA_B;
                ans[st.top()] = seqA_B;
                st.pop();
                seqA_B = !seqA_B;
            }
        }

        return ans;
    }
};