// class Solution
// {
// public:
//     int solve(vector<int> &days, vector<int> &costs, int index, int n)
//     {
//         if (index >= n)
//             return 0;

//         int option1 = costs[0] + solve(days, costs, index + 1, n);

//         int i;
//         for (i = index; i < n && days[i] < days[index] + 7; i++)
//             ;

//         int option2 = costs[1] + solve(days, costs, i, n);

//         for (i = index; i < n && days[i] < days[index] + 30; i++)
//             ;

//         int option3 = costs[2] + solve(days, costs, i, n);

//         return min(option1, min(option2, option3));
//     }
//     int mincostTickets(vector<int> &days, vector<int> &costs)
//     {
//         return solve(days, costs, 0, days.size());
//     }
// };

// Memoization approach

class Solution
{
public:
    int solve(vector<int> &days, vector<int> &costs, int index, int n, vector<int> &dp)
    {
        if (index >= n)
            return 0;

        if (dp[index] != -1)
            return dp[index];
        int option1 = costs[0] + solve(days, costs, index + 1, n, dp);

        int i;
        for (i = index; i < n && days[i] < days[index] + 7; i++)
            ;

        int option2 = costs[1] + solve(days, costs, i, n, dp);

        for (i = index; i < n && days[i] < days[index] + 30; i++)
            ;

        int option3 = costs[2] + solve(days, costs, i, n, dp);

        dp[index] = min(option1, min(option2, option3));
        return dp[index];
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> dp(n, -1);
        return solve(days, costs, 0, n, dp);
    }
};

// Tabulation approach
class Solution
{
public:
    int solve(vector<int> &days, vector<int> &costs, int index, int n, vector<int> &dp)
    {
        dp[n] = 0;
        for (int k = n - 1; k >= 0; k--)
        {

            int option1 = costs[0] + dp[k + 1];

            int i;
            for (i = k; i < n && days[i] < days[k] + 7; i++)
                ;

            int option2 = costs[1] + dp[i];

            for (i = k; i < n && days[i] < days[k] + 30; i++)
                ;

            int option3 = costs[2] + dp[i];

            dp[k] = min(option1, min(option2, option3));
        }

        return dp[0];
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> dp(n + 1, INT_MAX);
        return solve(days, costs, 0, n, dp);
    }
};