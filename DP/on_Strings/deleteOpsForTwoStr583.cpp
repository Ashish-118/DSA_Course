class Solution
{
public:
    int dp[501][501];
    int solve(string w1, string w2, int i, int j)
    {
        if (i >= w1.length() || j >= w2.length())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (w1[i] == w2[j])
        {
            return dp[i][j] = 1 + solve(w1, w2, i + 1, j + 1);
        }

        return dp[i][j] = max(solve(w1, w2, i + 1, j), solve(w1, w2, i, j + 1));
    }
    int minDistance(string word1, string word2)
    {

        memset(dp, -1, sizeof(dp));

        int longestSubseq = solve(word1, word2, 0, 0);

        return word1.length() - longestSubseq + word2.length() - longestSubseq;
    }
};