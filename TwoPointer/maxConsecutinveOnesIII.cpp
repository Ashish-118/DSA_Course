class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int l = 0, r = 0;
        int n = nums.size();
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                c++;
            r = i;
            if (c > k)
                break;
        }

        if (c > k)
            r--;

        int ans = 0;

        ans = max(ans, r - l + 1);

        while (r != n - 1)
        {
            int count = k;

            while (l < n && count >= k)
            {
                if (nums[l] == 0)
                {
                    count--;
                    l++;
                    break;
                }

                l++;
            }
            r++;
            while (r < n && count <= k)
            {

                if (nums[r] == 0)
                {
                    count++;
                    if (count > k)
                        continue;
                }

                r++;
            }
            r--;

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

// Optimized Approach

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0, maxLength = 0, zeroCount = 0;

        for (int right = 0; right < nums.size(); ++right)
        {
            if (nums[right] == 0)
            {
                zeroCount++;
            }
            while (zeroCount > k)
            {
                if (nums[left] == 0)
                {
                    zeroCount--;
                }
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};