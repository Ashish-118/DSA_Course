class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_set<string> st;

        for (auto a : arr1)
        {
            string s = "";
            string str = to_string(a);
            for (auto c : str)
            {
                s += c;
                st.insert(s);
            }
        }

        int ans = 0;

        for (auto a : arr2)
        {
            string s = "";
            string str = to_string(a);
            for (auto c : str)
            {
                s += c;
                if (st.find(s) != st.end())
                {
                    int len = s.length();
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};