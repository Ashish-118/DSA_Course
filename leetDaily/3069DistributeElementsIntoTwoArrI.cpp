class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        vector<int> arr1, arr2;
        int n = nums.size();

        vector<int> ans;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < n; i++)
        {
            int b1 = arr1.back();
            int b2 = arr2.back();

            if (b1 > b2)
            {
                arr1.push_back(nums[i]);
            }
            else
            {
                arr2.push_back(nums[i]);
            }
        }

        for (auto x : arr1)
            ans.push_back(x);
        for (auto x : arr2)
            ans.push_back(x);

        return ans;
    }
};