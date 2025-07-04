// class Solution
// {
// public:
//     vector<vector<int>> divideArray(vector<int> &nums, int k)
//     {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         int i = 0;
//         int check = 0;
//         while (i < nums.size() && check != -1)
//         {
//             vector<int> subAns;
//             if (abs(nums[i] - nums[i + 2]) > k)
//             {
//                 check = -1;
//                 break;
//             }
//             for (int j = i; j < i + 3; j++)
//             {
//                 subAns.push_back(nums[j]);
//             }
//             ans.push_back(subAns);
//             i = i + 3;
//         }
//         if (check == 0)
//             return ans;
//         else
//             return vector<vector<int>>();
//     }
// };

// better approach

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i += 3)
        {
            if (nums[i + 2] - nums[i] > k)
            {
                return {};
            }
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return ans;
    }
};