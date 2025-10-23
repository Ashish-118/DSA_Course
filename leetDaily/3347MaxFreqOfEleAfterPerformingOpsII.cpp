#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << endl;
            int maxVal = nums[i] + k;
            int minVal = nums[i] - k;
            int s = 0, e = n - 1;
            int minIndex = -1;

            while (s <= e)
            {
                int mid = s + (e - s) / 2;
                int maxR = nums[mid] + k;
                int minR = nums[mid] - k;

                if ((maxR <= maxVal && maxR >= minVal) || (minR >= minVal && minR <= maxVal))
                {
                    e = mid - 1;
                    minIndex = mid;
                }
                else
                {
                    s = mid + 1;
                }
            }

            s = 0, e = n - 1;

            int maxIndex = -1;

            while (s <= e)
            {
                int mid = s + (e - s) / 2;
                int maxR = nums[mid] + k;
                int minR = nums[mid] - k;

                if ((maxR <= maxVal && maxR >= minVal) || (minR >= minVal && minR <= maxVal))
                {
                    s = mid + 1;
                    maxIndex = mid;
                }
                else
                {
                    e = mid - 1;
                }
            }

            cout << "minIndex " << minIndex << " maxIndex " << maxIndex << endl;

            ans = max(ans, min(numOperations, maxIndex - minIndex) + 1);
        }

        return ans;
    }
};
