class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        set<int> st;
        for (auto &x : nums)
        {
            st.insert(x);
        }

        if (st.size() == 1)
            return 0;
        else
            return 1;
    }
};