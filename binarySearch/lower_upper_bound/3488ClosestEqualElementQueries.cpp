class Solution
{
public:
    vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
    {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans(queries.size(), 0);

        for (int q = 0; q < queries.size(); q++)
        {
            int target = nums[queries[q]];
            int len = mp[target].size();
            if (len == 1)
            {
                ans[q] = -1;
                continue;
            }

            int mini = INT_MAX;
            int findIdx =
                lower_bound(begin(mp[target]), end(mp[target]), queries[q]) -
                begin(mp[target]);

            if (findIdx != 0)
            {
                int nextLeft = findIdx - 1;
                int leftMost = 0;
                mini = min(mini, mp[target][findIdx] - mp[target][nextLeft]);
                mini =
                    min(mini, n - mp[target][findIdx] + mp[target][leftMost]);
            }

            if (findIdx != len - 1)
            {
                int nextRight = findIdx + 1;
                int RightMost = len - 1;

                mini = min(mini, mp[target][nextRight] - mp[target][findIdx]);
                mini =
                    min(mini, mp[target][findIdx] + n - mp[target][RightMost]);
            }

            ans[q] = mini;
        }

        return ans;
    }
};