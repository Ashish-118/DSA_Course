class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int x_plus_y = nums[i] + nums[j];

                int index = -1;

                int low = j + 1;
                int high = n - 1;

                while (low <= high)
                {
                    int mid = low + (high - low) / 2;

                    if (x_plus_y > nums[mid])
                    {
                        low = mid + 1;
                        index = max(index, mid);
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }

                if (index != -1)
                {
                    ans += (index - j);
                }
            }
        }

        return ans;
    }
}; // Time Complexity: O(N^2 logN)

// using two pointer approach

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;

        sort(begin(nums), end(nums));
        int count = 0;

        for (int k = n - 1; k > 1; k--)
        {                         // k is the largest side
            int i = 0, j = k - 1; // two pointers

            while (i < j)
            {
                if (nums[i] + nums[j] > nums[k])
                {
                    count += (j - i); // all pairs (i..j-1, j) will satisfy the
                                      // inequality
                    j--;
                }
                else
                {
                    i++;
                }
            }
        }

        return count;
    }
};
