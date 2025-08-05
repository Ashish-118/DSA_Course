class Solution
{
public:
    long long maxSubarrays(int n, vector<vector<int>> &conflictingPairs)
    {
        long long valid = 0;

        vector<vector<int>> conflictingPoints(n + 1);
        for (auto &p : conflictingPairs)
        {
            int a = min(p[0], p[1]);
            int b = max(p[0], p[1]);
            conflictingPoints[b].push_back(a);
        }

        int maxConflict = 0;
        int secondMaxConflict = 0;
        vector<long long> extra(n + 1, 0);
        // extra[i] means  you will get this much subArrays extra when you will remove conflicting point i

        for (int end = 1; end <= n; end++)
        {

            for (auto &x : conflictingPoints[end])
            {
                if (x >= maxConflict)
                {
                    secondMaxConflict = maxConflict;
                    maxConflict = x;
                }
                else if (x > secondMaxConflict)
                {
                    secondMaxConflict = x;
                }
            }

            valid += end - maxConflict;
            extra[maxConflict] += maxConflict - secondMaxConflict;
        }
        return valid + *max_element(extra.begin(), extra.end());
    }
};