class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();

        set<pair<int, int>> st;
        vector<int> count(m, 0);

        for (int col = 0; col < m; col++)
        {
            st.insert({count[col], col});
        }

        int ans = INT_MIN;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (matrix[row][col])
                {
                    auto iter = st.find({count[col], col});
                    st.erase(iter);
                    count[col]++;
                    st.insert({count[col], col});
                }
                else
                {
                    auto iter = st.find({count[col], col});
                    st.erase(iter);
                    count[col] = 0;
                    st.insert({count[col], col});
                }
            }
            int i = 0;

            for (auto x : st)
            {
                ans = max(ans, count[x.second] * (m - i));
                i++;
            }
        }

        return ans;
    }
};