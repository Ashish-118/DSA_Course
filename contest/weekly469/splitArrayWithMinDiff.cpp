class Solution
{
public:
    long long splitArray(vector<int> &nums)
    {
        int index = -1;
        int n = nums.size();

        long long int g1 = nums[0];
        int i = 0;
        while (i < (n - 1) && nums[i] < nums[i + 1])
        {
            g1 += nums[++i];
        }
        index = i;
        long long g2 = 0;
        long long top = nums[index] + 1;
        i++;
        while (i < n && top > nums[i])
        {
            top = nums[i];
            g2 += nums[i];
            i++;
        }

        cout << i << " " << g1 << " " << g2 << endl;
        long long poss = INT_MAX;
        if ((index + 1) == n || nums[index] > nums[index + 1])
        {
            poss = abs((g1 - nums[index]) - (g2 + nums[index]));
        }
        if (i == n)
            return min(abs(g1 - g2), poss);
        else
            return -1;
    }
};
©leetcode