class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        vector<string> digitLog;

        set<pair<string, string>> st;

        for (auto &l : logs)
        {
            if (isdigit(l.back()))
            {
                digitLog.push_back(l);
            }
            else
            {
                int len = l.length();
                auto first_space = l.find(' ');

                st.insert(
                    {l.substr(first_space + 1), l.substr(0, first_space)});
            }
        }

        vector<string> ans;

        for (auto s : st)
        {
            ans.push_back(s.second + ' ' + s.first);
        }
        for (auto d : digitLog)
            ans.push_back(d);

        return ans;
    }
};