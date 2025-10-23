#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> freq;
        for (int n : nums)
            freq[n]++;

        int maxNum = nums.back();
        int ans = 0;

        // loop over each possible target value
        for (int target = 0; target <= maxNum; target++)
        {
            int maxRange = target + k;
            int minRange = target - k;

            // count how many elements fall in [minRange, maxRange]
            int upperIndex = upper_bound(nums.begin(), nums.end(), maxRange) - nums.begin();
            int lowerIndex = lower_bound(nums.begin(), nums.end(), minRange) - nums.begin();

            int countInRange = upperIndex - lowerIndex;
            int existing = freq[target];
            int canChange = min(numOperations, countInRange - existing);

            freq[target] = existing + canChange;
            ans = max(ans, freq[target]);
        }

        return ans;
    }
};
