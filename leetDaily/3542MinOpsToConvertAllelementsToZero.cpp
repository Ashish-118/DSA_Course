class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        set<int> st;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            auto it = st.upper_bound(nums[i]);
            st.erase(it, st.end());
            if (nums[i] == 0)
                continue;
            if (st.find(nums[i]) == st.end())
            {
                ans++;
                st.insert(nums[i]);
            }
        }

        return ans;
    }
}; // time complexity: O(nlogn)  space complexity: O(n)