class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        unordered_set<int> st;
        int n = A.size();

        int prev = 0;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (A[i] == B[i])
            {
                prev++;
            }
            else
            {
                if (st.find(A[i]) != st.end())
                {
                    prev++;
                }
                if (st.find(B[i]) != st.end())
                {
                    prev++;
                }
            }
            ans[i] = prev;

            st.insert(A[i]);
            st.insert(B[i]);
        }

        return ans;
    }
};