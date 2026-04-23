class Solution
{
public:
    vector<long long> distance(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, vector<int>> distinct_elements;
        for (int i = 0; i < n; i++)
        {
            distinct_elements[nums[i]].push_back(i);
        }
        vector<long long> ans(n, 0);

        for (auto m : distinct_elements)
        {
            int element = m.first;
            auto indices = m.second;
            long long j = 0;
            int x = 0;

            // forward pass
            for (auto i : indices)
            {
                ans[i] += (1LL * x * i - j);
                j += i;
                x++;
            }

            // reverse pass
            j = 0;
            x = 0;
            for (int y = indices.size() - 1; y >= 0; y--)
            {
                int i = indices[y];
                ans[i] += (j - 1LL * x * i);
                j += i;
                x++;
            }
        }

        return ans;
    }
};