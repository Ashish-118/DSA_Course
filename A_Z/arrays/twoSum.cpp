class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, vector<pair<int, bool>>> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]].push_back({i, true});
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]][0].second = false;
            int req = target - nums[i];
            bool breakL = false;
            for (auto x : m[req])
            {
                if (x.second && x.first != i)
                {
                    ans.push_back(i);
                    ans.push_back(x.first);
                    breakL = true;
                    break;
                }
            }
            if (breakL)
                break;

            m[nums[i]][0].second = true;
        }
        return ans;
    }
};