class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {

        string windowStr = "";
        unordered_set<string> st;

        for (int i = 0; i < s.length(); i++)
        {
            windowStr += s[i];
            if (windowStr.length() == k)
            {
                st.insert(windowStr);
                windowStr = windowStr.substr(1);
            }
        }

        return st.size() == pow(2, k);
    }
};