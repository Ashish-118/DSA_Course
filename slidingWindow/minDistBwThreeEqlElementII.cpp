class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        vector<pair<int, int>> v;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            v.push_back({nums[i], i});
        }

        sort(begin(v), end(v));

        int left = 0, ans = INT_MAX;

        for (int right = 0; right < n; right++)
        {

            if (v[left].first != v[right].first)
            {
                left = right;
            }

            if ((right - left + 1) == 3)
            {
                ans = min(ans, v[left + 1].second - v[left].second + v[right].second - v[left + 1].second + v[right].second - v[left].second);
                left++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
©leetcode