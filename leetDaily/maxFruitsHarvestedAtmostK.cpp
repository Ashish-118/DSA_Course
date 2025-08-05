class Solution
{
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        int n = fruits.size();

        vector<int> prefixSum(n, 0);
        vector<int> positions(n, 0);

        for (int i = 0; i < n; i++)
        {
            positions[i] = fruits[i][0];
            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i - 1] : 0);
        }

        int maxi = 0;
        for (int d = 0; d <= k / 2; d++)
        {
            // case 1 move d steps to the left first
            int remain = k - 2 * d;
            int i = startPos - d;
            int j = startPos + remain;

            int left = lower_bound(begin(positions), end(positions), i) - begin(positions);
            int right = upper_bound(begin(positions), end(positions), j) - begin(positions) - 1;

            if (left <= right)
            {
                int ans = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxi = max(maxi, ans);
            }

            //  case 2 move d steps to the right first

            remain = k - 2 * d;
            i = startPos - remain;
            j = startPos + d;
            left = lower_bound(begin(positions), end(positions), i) - begin(positions);
            right = upper_bound(begin(positions), end(positions), j) - begin(positions) - 1;

            if (left <= right)
            {
                int ans = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);
                maxi = max(maxi, ans);
            }
        }
        return maxi;
    }
}; // time complexity: O(k * log n)