class Solution
{
public:
    vector<vector<int>> dp;
    int solve(int i, int prev, vector<string> &words, int n)
    {
        if (i >= n)
            return 0;

        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int take = 0;
        bool check = true;
        int count = 0;
        if (prev != -1)
        {
            int j = 0, x = 0;
            check = (words[i].length() - words[prev].length() == 1);
            while (x < words[prev].length() && j < words[i].length())
            {

                if (words[prev][x] != words[i][j])
                {

                    count++;
                    x--;
                }
                if (count > 1)
                    break;
                x++;
                j++;
            }

            while (j < words[i].length())
            {
                count++;
                j++;
            }
        }

        if (prev == -1 || (check && count == 1))
        {

            take = 1 + solve(i + 1, i, words, n);
        }

        int notTake = solve(i + 1, prev, words, n);
        return dp[i][prev + 1] = max(take, notTake);
    }
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(begin(words), end(words),
             [&](string &a, string &b)
             { return a.length() < b.length(); });

        dp = vector<vector<int>>(n, vector<int>(n + 1, -1));

        return solve(0, -1, words, n);
    }
};