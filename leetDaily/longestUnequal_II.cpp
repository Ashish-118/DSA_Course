// Brute force solution
// Time complexity: O(n^2)

// class Solution
// {
// public:
//     bool isHumming(string w1, string w2)
//     {
//         bool c1 = (w1.length() == w2.length());
//         bool c2 = true;

//         int h = 0;

//         if (c1)
//         {

//             for (int i = 0; i < w2.length(); i++)
//             {
//                 if (w1[i] != w2[i])
//                 {
//                     h++;
//                 }
//                 if (h > 1)
//                 {
//                     c2 = false;
//                     break;
//                 }
//             }
//         }

//         return c1 && c2;
//     }

//     void solve(int top, int index, vector<string> &sol, vector<string> &ans, int n, vector<string> &words, vector<int> &groups)
//     {
//         if (index >= n)
//         {
//             if (sol.size() < ans.size())
//             {
//                 sol = ans;
//             }

//             return;
//         }

//         string last = (ans.empty() ? "" : ans.back());

//         for (int i = index; i < n; i++)
//         {

//             if (index == 0 || (top != groups[i]) && isHumming(words[i], last))
//             {
//                 ans.push_back(words[i]);
//                 solve(groups[i], i + 1, sol, ans, n, words, groups);
//                 ans.pop_back();
//             }

//             if (i == (n - 1))
//             {
//                 if (sol.size() < ans.size())
//                 {
//                     sol = ans;
//                 }
//             }
//         }
//     }
//     vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
//     {
//         vector<string> sol;
//         vector<string> ans;

//         solve(-1, 0, sol, ans, words.size(), words, groups);
//         return sol;
//     }
// };

//// Optimized solution

class Solution
{
public:
    bool differByOneChar(string word1, string word2)
    {
        if (word1.length() != word2.length())
            return false;
        int diffCount = 0;
        for (int i = 0; i < word1.length(); i++)
            diffCount += word1[i] != word2[i];
        return diffCount == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = groups.size();
        vector<int> dp(n, 1), parent(n, -1);
        int maxi = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (groups[i] != groups[j] &&
                    differByOneChar(words[i], words[j]) &&
                    dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            maxi = max(maxi, dp[i]);
        }

        vector<string> result;
        for (int i = 0; i < n; i++)
        {
            if (maxi == dp[i])
            {
                while (i != -1)
                {
                    result.push_back(words[i]);
                    i = parent[i];
                }
                break;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
