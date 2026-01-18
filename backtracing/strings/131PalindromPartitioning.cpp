class Solution
{
public:
    void solve(int i, string s, vector<string> &temp,
               vector<vector<string>> &ans)
    {
        if (i >= s.length())
        {
            bool check = true;
            for (auto x : temp)
            {
                string y = x;
                reverse(begin(y), end(y));
                if (y != x)
                {
                    check = false;
                    break;
                }
            }

            if (check)
                ans.push_back(temp);

            return;
        }

        temp.push_back(string(1, s[i]));
        solve(i + 1, s, temp, ans);
        temp.pop_back();

        if (!temp.empty())
        {
            string back = temp.back();
            temp.pop_back();
            back += s[i];
            temp.push_back(back);
            solve(i + 1, s, temp, ans);
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;

        vector<string> temp;

        solve(0, s, temp, res);
        return res;
    }
};