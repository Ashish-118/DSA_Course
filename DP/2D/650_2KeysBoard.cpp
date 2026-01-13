// recurrsion

class Solution
{
public:
    int solve(int curr, int n, int prev)
    {
        if (curr == n)
            return 1;
        if (curr > n)
            return 1e5;

        int pastePrev = INT_MAX;
        if (prev != -1)
        {
            pastePrev = 1 + solve(curr + prev, n, prev);
        }

        int copyPaste = 2 + solve(curr + curr, n, curr);

        return min(pastePrev, copyPaste);
    }
    int minSteps(int n)
    {

        return solve(1, n, -1) - 1;
    }
}; // time complexity: O(2^n);

// recursion + dp

class Solution
{
public:
    vector<vector<int>> dp;

    int solve(int curr, int n, int prev)
    {

        if (curr == n)
            return 1;
        if (curr > n)
            return 1e5;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        int pastePrev = INT_MAX;
        if (prev != -1)
            pastePrev = 1 + solve(curr + prev, n, prev);

        int copyPaste = 2 + solve(curr + curr, n, curr);

        return dp[curr][prev + 1] = min(pastePrev, copyPaste);
    }

    int minSteps(int n)
    {
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        return solve(1, n, -1) - 1;
    }
}; // time complexity : O(n^2);
