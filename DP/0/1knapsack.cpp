#include <bits/stdc++.h>
int solve(vector<int> weight, vector<int> value, int index, int capacity, vector<vector<int>> &dp)
{

    if (index == 0)
    {
        if (weight[index] <= capacity)
            return value[index];
        else
            return 0;
    }
    if (dp[index][capacity] != -1)
        return dp[index][capacity];
    int include = 0;
    if (weight[index] <= capacity)
    {
        include = solve(weight, value, index - 1, capacity - weight[index], dp) + value[index];
    }
    int exclude = solve(weight, value, index - 1, capacity, dp);
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
} // Function to solve the 0/1 Knapsack problem using memoization
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    for (int w = 0; w <= maxWeight; w++)
    {
        if (weight[0] <= w)
        {
            dp[0][w] = value[0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int include = 0;
            if (weight[i] <= w)
            {
                include = dp[i - 1][w - weight[i]] + value[i];
            }
            int exclude = dp[i - 1][w];
            dp[i][w] = max(include, exclude);
        }
    }

    return dp[n - 1][maxWeight];
} // Function to solve the 0/1 Knapsack problem using tabulation

// space optimization

#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);
    vector<int> curr(maxWeight + 1, 0);

    for (int w = 0; w <= maxWeight; w++)
    {
        if (weight[0] <= w)
        {
            prev[w] = value[0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int include = 0;
            if (weight[i] <= w)
            {
                include = prev[w - weight[i]] + value[i];
            }
            int exclude = prev[w];
            curr[w] = max(include, exclude);
        }
        prev = curr;
    }

    return prev[maxWeight];
}

// more optimised using only one vector

#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);

    for (int w = 0; w <= maxWeight; w++)
    {
        if (weight[0] <= w)
        {
            prev[w] = value[0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int w = maxWeight; w >= 0; w--)
        {
            int include = 0;
            if (weight[i] <= w)
            {
                include = prev[w - weight[i]] + value[i];
            }
            int exclude = prev[w];
            prev[w] = max(include, exclude);
        }
    }

    return prev[maxWeight];
}
