class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        vector<int> ans;
        int j = 0;
        int l = nums.size();
        while (j < l)
        {
            if (key == nums[j])
            {
                int low = max(0, j - k);
                int high = min(l - 1, j + k);
                for (int i = low; i <= high; i++)
                {
                    if (ans.empty() || ans.back() < i)
                        ans.push_back(i);
                }
            }
            j++;
        }
        return ans;
    }
};
