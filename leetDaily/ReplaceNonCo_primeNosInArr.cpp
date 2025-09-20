class Solution
{
public:
    vector<int> replaceNonCoprimes(vector<int> &nums)
    {
        stack<int> st;

        for (int i = 0; i < nums.size(); i++)
        {
            int to_check_with = nums[i];

            while (!st.empty() && gcd(st.top(), to_check_with) > 1)
            {
                int topVal = st.top();
                st.pop();
                to_check_with =
                    (1LL * topVal * to_check_with) / gcd(topVal, to_check_with);
            }

            st.push(to_check_with);
        }

        vector<int> v;
        while (!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }

        reverse(v.begin(), v.end());
        return v;
    }
};