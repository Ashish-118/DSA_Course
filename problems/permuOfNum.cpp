class Solution {
void solve(vector<vector<int>> &ans, vector<int> dup, vector<int> output,vector<int> given_arr, int index, int j)
{

    if (index >= given_arr.size())
    {
        ans.push_back(output);
        return;
    }

    if (index != 0)
    {
        dup.erase(dup.begin()+j);
    }

    for (int i = 0; i < dup.size(); i++)
    {
        output.push_back(dup[i]);
        solve(ans, dup, output, given_arr, index + 1, i);
        output.pop_back();
    }
}

// babbar's method

// void solve(vector<int> nums, vector<vector<int>>& ans, int index){
//     if(index>=nums.size()){
//         ans.push_back(nums);
//         return;
//     }

//     for(int i=index; i<nums.size(); i++){
//         swap(nums[index],nums[i]);
//         solve(nums,ans,index+1);
//         swap(nums[index],nums[i]);
//     }
// }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(ans, nums, output, nums, 0, 0);

        //for babbar method
        // solve(nums,ans,0);
    return ans;
    }
};