void backtrack(vector<vector<int>> &dp, set<string> &st, unordered_map<string, bool> &mp,
               string &text1, string &text2, int i, int j, string &res)
{
    if (i == 0 || j == 0)
    {
        string temp = res;
        reverse(temp.begin(), temp.end());
        st.insert(temp);
        return;
    }

    string key = to_string(i) + "$" + to_string(j) + "$" + res;
    if (mp.find(key) != mp.end())
        return;
    mp[key] = true;

    if (text1[i - 1] == text2[j - 1])
    {
        res.push_back(text1[i - 1]);
        backtrack(dp, st, mp, text1, text2, i - 1, j - 1, res);
        res.pop_back();
    }
    else
    {
        if (dp[i][j] == dp[i - 1][j])
        {
            backtrack(dp, st, mp, text1, text2, i - 1, j, res);
        }
        if (dp[i][j] == dp[i][j - 1])
        {
            backtrack(dp, st, mp, text1, text2, i, j - 1, res);
        }
    }
}

vector<string> allLCS(string &text1, string &text2)
{
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    set<string> st;
    unordered_map<string, bool> mp;
    string res = "";
    backtrack(dp, st, mp, text1, text2, n, m, res);

    return vector<string>(st.begin(), st.end());
}
