/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int solve(TreeNode *root, int &maxi)
    {
        if (root == NULL)
            return 0;
        int left = solve(root->left, maxi);
        int right = solve(root->right, maxi);
        int sum = root->val + left + right;
        if (left != 0)
        {
            maxi = max(maxi, left + root->val);
        }
        if (right != 0)
        {
            maxi = max(maxi, right + root->val);
        }
        maxi = max(maxi, root->val);

        maxi = max(maxi, sum);

        int temp = max(max(right + root->val, left + root->val), root->val);

        return temp;
    }
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};