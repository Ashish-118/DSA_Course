class Solution
{
public:
    bool uniformArray(vector<int> &nums1)
    {
        int n = nums1.size();

        bool checkParity = true;

        for (int i = 1; i < n; i++)
        {
            int prevParity = nums1[i - 1] % 2;
            if (prevParity != (nums1[i] % 2))
            {
                checkParity = false;
                break;
            }
        }

        if (checkParity)
            return true;

        // case :  we can only convert entire array to odd if we have 0th element odd

        int mini = INT_MAX;

        for (auto x : nums1)
        {
            mini = min(mini, x);
        }

        if (mini & 1)
            return true;

        return false;
    }
};