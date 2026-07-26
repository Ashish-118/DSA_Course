class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        int n = nums.size();
        sort(begin(nums), end(nums));
        set<vector<int>> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int tar = -(nums[i] + nums[j]);

                int idx = -1;
                int lo = j + 1, hi = n - 1;

                while (lo <= hi)
                {
                    int mid = lo + (hi - lo) / 2;

                    if (tar == nums[mid])
                    {
                        idx = mid;
                        break;
                    }
                    else if (tar > nums[mid])
                    {
                        lo = mid + 1;
                    }
                    else
                    {
                        hi = mid - 1;
                    }
                }

                if (idx != -1)
                {
                    vector<int> ans = {nums[i], nums[j], tar};
                    sort(begin(ans), end(ans));

                    st.insert(ans);
                }
            }
        }

        vector<vector<int>> result;

        for (auto s : st)
        {
            result.push_back(s);
        }

        return result;
    }
};


// the most optimal approach

class Solution
{
public:
    void twoSum(vector<int> &nums, int k, vector<vector<int>> &result, int target)
    {
        // Two pointer technique (Sorted array) Things you must not forget in interviews

        int i = k, j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] > target)
                j--;
            else if (nums[i] + nums[j] < target)
                i++;
            else
            {
                result.push_back({-target, nums[i], nums[j]});
                while (i < j && nums[i] == nums[i + 1])
                    i++;
                while (i < j && nums[j] == nums[j - 1])
                    j--;
                i++; // Things you must not forget in interviews
                j--; // Things you must not forget in interviews
            }
        }
    }
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3) // Things you must not forget in interviews
            return {};
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        { //(i<nums.size()-2)Things you must not forget in interviews
            if (i != 0 && nums[i] == nums[i - 1])
            { // Things you must not forget in interviews
                continue;
            }
            twoSum(nums, i + 1, result, -nums[i]);
        }
        return result;
    }
};