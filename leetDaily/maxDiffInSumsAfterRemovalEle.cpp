class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        int n3 = nums.size(), n = n3 / 3;
        vector<long long> left(n3, 0);
        vector<long long> right(n3, 0);

        priority_queue<int> maxHeap;
        long long leftSum = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            leftSum += nums[i];
            maxHeap.push(nums[i]);

            if (maxHeap.size() > n)
            {
                leftSum -= maxHeap.top();
                maxHeap.pop();
            }

            left[i] = leftSum;
        }

        long long rightSum = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = n3 - 1; i >= n; i--)
        {
            rightSum += nums[i];
            minHeap.push(nums[i]);
            if (minHeap.size() > n)
            {
                rightSum -= minHeap.top();
                minHeap.pop();
            }
            right[i] = rightSum;
        }

        long long result = LLONG_MAX;

        for (int i = n - 1; i <= 2 * n - 1; i++)
        {
            result = min(result, left[i] - right[i + 1]);
        }
        return result;
    }
};