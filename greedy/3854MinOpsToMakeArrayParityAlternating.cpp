class Solution
{
public:
    vector<int> makeParityAlternating(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return {0, 0};
        long long cost0 = 0, cost1 = 0;
        // 01010101
        for (int i = 0; i < n; i++)
        { // 010101, 101010
            if ((nums[i] & 1) != (i & 1))
                cost0++;
            if ((nums[i] & 1) != ((i + 1) & 1))
                cost1++;
        }
        long long minCost = min(cost0, cost1);
        long long bestRange = LLONG_MAX;
        for (int t = 0; t < 2; t++)
        {
            long long cost = (t == 0 ? cost0 : cost1); // t=0, 01010101 and t=1, 10101010
            if (cost != minCost)
                continue;
            long long mx = -4e18, mn = 4e18;
            vector<int> changed;
            for (int i = 0; i < n; i++)
            {
                long long v = nums[i];
                int targetParity;
                if (t == 0)
                    targetParity = (i & 1); // i%2
                else
                    targetParity = (i & 1) ^ 1; // (i+1)%2
                if ((v & 1) == targetParity)
                { // Fixed number
                    mx = max(mx, v);
                    mn = min(mn, v);
                }
                else
                    changed.push_back(v); // non fixed number, so we have to apply operation (+1,-1)
            }
            if (!changed.empty())
            {
                int m = changed.size();
                if (m == 1)
                {
                    long long x = changed[0];
                    for (auto add : {-1, 1})
                    {
                        bestRange = min(bestRange, max(mx, x + add) - min(mn, x + add));
                    }
                }
                else
                {
                    sort(changed.begin(), changed.end());
                    long long x = changed[0], y = changed[m - 1]; // x....y +1,-1
                    for (int dx : {-1, 1})
                    {
                        for (int dy : {-1, 1})
                        {
                            bestRange = min(bestRange, max({mx, x + dx, y + dy}) - min({mn, x + dx, y + dy}));
                        }
                    }
                }
            }
            else
                bestRange = min(bestRange, mx - mn);
        }
        return {(int)minCost, (int)bestRange};
    }
};