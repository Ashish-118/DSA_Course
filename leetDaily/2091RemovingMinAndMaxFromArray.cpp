class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int minIdx = 0, maxIdx = 0;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[minIdx] > nums[i])
            {
                minIdx = i;
            }

            if (nums[maxIdx] < nums[i])
            {
                maxIdx = i;
            }
        }

        int x = min(minIdx, maxIdx);
        int y = max(minIdx, maxIdx);

        int left1 = x + 1;
        int left2 = y + 1 - left1;

        int right1 = n - y;
        int right2 = n - x - right1;

        int case3 = left1 + right1;

        return min({left1 + left2, right1 + right2, case3});
    }
};