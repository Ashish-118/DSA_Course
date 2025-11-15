class Solution
{
public:
    string solve(string s1, string s2, int i, int j, vector<vector<string>> &dp)
    {
        if (i >= s1.length() && j >= s2.length())
        {
            return "";
        }
        else if (i >= s1.length())
        {
            return s2.substr(j);
        }
        else if (j >= s2.length())
        {
            return s1.substr(i);
        }
        if (dp[i][j] != "")
            return dp[i][j];
        if (s1[i] == s2[j])
        {
            return dp[i][j] = s1[i] + solve(s1, s2, i + 1, j + 1, dp);
        }
        else
        {
            string str1 = s1[i] + solve(s1, s2, i + 1, j, dp);
            string str2 = s2[j] + solve(s1, s2, i, j + 1, dp);

            if (str1.length() < str2.length())
                return dp[i][j] = str1;
            else
                return dp[i][j] = str2;
        }
    }
    string shortestCommonSupersequence(string str1, string str2)
    {
        vector<vector<string>> dp(str1.length(),
                                  vector<string>(str2.length(), ""));
        return solve(str1, str2, 0, 0, dp);
    }
}; // O(n*m) time and O(n*m) space

// bottom up approach

string shortestCommonSupersequence(string str1, string str2)
{
    vector<vector<string>> dp(str1.length() + 1,
                              vector<string>(str2.length() + 1, ""));
    int n1 = str1.length();
    int n2 = str2.length();

    for (int i = n1; i >= 0; i--)
    {
        for (int j = n2; j >= 0; j--)
        {
            if (i >= n1)
            {
                dp[i][j] = str2.substr(j);
            }
            else if (j >= str2.length())
            {
                dp[i][j] = str1.substr(i);
            }
            else
            {
                if (str1[i] == str2[j])
                {
                    dp[i][j] = str1[i] + dp[i + 1][j + 1];
                }
                else
                {
                    string s1 = str1[i] + dp[i + 1][j];
                    string s2 = str2[j] + dp[i][j + 1];

                    if (s1.length() < s2.length())
                        dp[i][j] = s1;
                    else
                        dp[i][j] = s2;
                }
            }
        }
    }
    return dp[0][0];
}

// space optimised approach

string shortestCommonSupersequence(string str1, string str2)
{
    // vector<vector<string>> dp(str1.length() + 1,
    //                           vector<string>(str2.length() + 1, ""));

    vector<string> curr(str2.length() + 1, "");
    vector<string> prev(str2.length() + 1, "");
    int n1 = str1.length();
    int n2 = str2.length();

    for (int i = n1; i >= 0; i--)
    {
        for (int j = n2; j >= 0; j--)
        {
            if (i >= n1)
            {
                curr[j] = str2.substr(j);
            }
            else if (j >= str2.length())
            {
                curr[j] = str1.substr(i);
            }
            else
            {
                if (str1[i] == str2[j])
                {
                    curr[j] = str1[i] + prev[j + 1];
                }
                else
                {
                    string s1 = str1[i] + prev[j];
                    string s2 = str2[j] + curr[j + 1];

                    if (s1.length() < s2.length())
                        curr[j] = s1;
                    else
                        curr[j] = s2;
                }
            }
        }
        prev = curr;
        fill(begin(curr), end(curr), "");
    }
    return prev[0];
}

// best approach using LCS without memory limit exceeding

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();

        // Step 1: Compute LCS table (from back)
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (str1[i] == str2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        // Step 2: Build the shortest supersequence from the back logic
        int i = 0, j = 0;
        string ans = "";

        while (i < n && j < m)
        {
            if (str1[i] == str2[j])
            {
                ans += str1[i];
                i++;
                j++;
            }
            else if (dp[i + 1][j] >= dp[i][j + 1])
            {
                ans += str1[i];
                i++;
            }
            else
            {
                ans += str2[j];
                j++;
            }
        }

        // Step 3: Add any remaining part
        while (i < n)
            ans += str1[i++];
        while (j < m)
            ans += str2[j++];

        return ans;
    }
};
