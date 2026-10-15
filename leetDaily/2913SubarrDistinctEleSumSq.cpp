class Solution
{
public:
    int sumCounts(vector<int> &nums)
    {
        int n = nums.size();

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                unordered_set<int> st;

                for (int x = i; x <= j; x++)
                {
                    st.insert(nums[x]);
                }

                ans += (st.size() * st.size());
            }
        }

        return ans;
    }
};