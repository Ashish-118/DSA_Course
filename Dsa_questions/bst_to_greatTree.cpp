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
    void solve(TreeNode *&root, int &temp)
    {
        if (root == NULL)
        {
            return;
        }

        solve(root->right, temp);
        root->val = temp + root->val;
        temp = root->val;
        solve(root->left, temp);
    }

public:
    TreeNode *convertBST(TreeNode *root)
    {
        int temp = 0;

        solve(root, temp);
        return root;
    }
};