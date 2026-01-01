/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    void solve(TreeNode *root, vector<vector<int>> &ans, vector<int> &temp,
               int sum, int target)
    {

        if (!root)
            return;
        else if (!root->left && !root->right)
        {
            if (target == (sum + root->val))
            {
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
            }
        }

        temp.push_back(root->val);
        solve(root->left, ans, temp, sum + root->val, target);
        solve(root->right, ans, temp, sum + root->val, target);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int target = 0;

        solve(root, ans, temp, 0, targetSum);

        return ans;
    }
};