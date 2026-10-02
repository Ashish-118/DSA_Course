class Solution
{
public:
    void solve(int open, int close, string &temp, vector<string> &ans,
               int track)
    {
        if (open == 0 && close == 0 && track == 0)
        {
            ans.push_back(temp);
            return;
        }
        else if (track < 0)
        {
            return;
        }

        if (open)
        {
            temp += '(';
            solve(open - 1, close, temp, ans, track + 1);
            temp.pop_back();
        }

        if (temp.length() && close)
        {
            temp += ')';
            solve(open, close - 1, temp, ans, track - 1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string temp = "";
        solve(n, n, temp, ans, 0);

        return ans;
    }
};