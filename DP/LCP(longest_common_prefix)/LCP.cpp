vector<vector<int>> LongestCommonPrefixMatrix(string s)
{
    int n = s.length();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
    {
        result[n - 1][j] = result[j][n - 1] = (s[j] == s[n - 1]) ? 1 : 0;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            result[i][j] = (s[i] == s[j]) ? 1 + result[i + 1][j + 1] : 0;
        }
    }

    return result;
}