class Solution
{
public:
    int countMagicalPairs(string s)
    {
        int n = s.length();
        vector<vector<int>> v1(n, vector<int>(n + 1, 0));
        vector<vector<int>> v2(n, vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++)
        {
            unordered_set<char> st;
            for (int j = i; j < n; j++)
            {
                st.insert(s[j]);
                v1[i][j] = st.size();
                v2[i][st.size()]++;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_set<char> st;
            for (int j = i; j < n - 1; j++)
            {
                st.insert(s[j]);
                int size = st.size();
                ans += v2[j + 1][size];

                // cout << "i " << i << " j " << j << " ans " << ans << endl;
            }
        }

        return ans;
    }
};