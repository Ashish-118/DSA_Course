class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size(), m = matrix[0].size();
        int maxSum = INT_MIN;

        for (int left = 0; left < m; left++)
        {
            vector<int> dp(n, 0);

            for (int right = left; right < m; right++)
            {
                for (int row = 0; row < n; row++)
                    dp[row] += matrix[row][right];

                // find max subarray sum <= k
                set<int> prefix;
                prefix.insert(0);
                int currSum = 0;

                for (int x : dp)
                {
                    currSum += x;

                    auto it = prefix.lower_bound(currSum - k);
                    if (it != prefix.end())
                        maxSum = max(maxSum, currSum - *it);

                    prefix.insert(currSum);
                }
            }
        }
        return maxSum;
    }
};
