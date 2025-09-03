class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {

        int len1 = text1.length(), len2 = text2.length();
        vector<int> prev(len2 + 1, 0);
        vector<int> curr(len2 + 1, 0);

        for (int i = len1 - 1; i >= 0; i--)
        {
            for (int j = len2 - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                {
                    curr[j] = 1 + prev[j + 1];
                }
                else
                {
                    curr[j] = max(prev[j], curr[j + 1]);
                }
            }
            prev = curr;
        }

        return prev[0];
    }

    int longestPalindromeSubseq(string s)
    {
        string str = s;
        reverse(str.begin(), str.end());
        return longestCommonSubsequence(s, str);
    }
};