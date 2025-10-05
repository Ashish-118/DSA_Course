class Solution
{
public:
    unordered_map<int, unordered_map<int, int>> dp;
    int solve(int prev, string s, int index)
    {
        if (index >= s.length())
            return 0;
        if (dp.count(index) && dp[index].count(prev))
            return dp[index][prev];

        if ((s[index] - '0') >= prev)
        {

            int min1 = INT_MAX, min2 = INT_MAX;
            if (0 >= prev)
            {
                min1 = solve(0, s, index + 1) + ((s[index] - '0') != 0 ? 1 : 0);
            }
            if (1 >= prev)
            {
                min2 = solve(1, s, index + 1) + ((s[index] - '0') != 1 ? 1 : 0);
            }
            return dp[index][prev] = min(min1, min2);
        }
        else
        {
            return dp[index][prev] = 1 + solve(1, s, index + 1);
        }
    }
    int minFlipsMonoIncr(string s)
    {

        return solve(0, s, 0);
    }
}; // recursion + memoization --XXXXX error

// recursion + memoization

class Solution
{
public:
    int n;

    int solve(string &s, int curr_index, int prev_val, vector<vector<int>> &t)
    {
        if (curr_index >= n)
            return 0;

        if (t[curr_index][prev_val] != -1)
            return t[curr_index][prev_val];

        int flip = INT_MAX;
        int no_flip = INT_MAX;

        if (s[curr_index] == '0')
        {

            if (prev_val == 1)
            {
                flip = 1 + solve(s, curr_index + 1, 1, t);
            }
            else
            {
                flip = 1 + solve(s, curr_index + 1, 1, t);
                no_flip = solve(s, curr_index + 1, 0, t);
            }
        }

        else if (s[curr_index] == '1')
        {
            if (prev_val == 1)
            {
                no_flip = solve(s, curr_index + 1, 1, t);
            }
            else
            {
                flip = 1 + solve(s, curr_index + 1, 0, t);
                no_flip = solve(s, curr_index + 1, 1, t);
            }
        }

        return t[curr_index][prev_val] = min(flip, no_flip);
    }

    int minFlipsMonoIncr(string s)
    {
        n = s.length();

        vector<vector<int>> t(n + 1, vector<int>(2, -1));

        return solve(s, 0, 0, t);
    }
}; // O(n) time and O(n) space