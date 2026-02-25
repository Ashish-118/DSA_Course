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
    int ans;
    void solve(TreeNode *root, int val)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            ans += ((val << 1) | root->val);
            return;
        }

        int num = (val << 1) | root->val;
        solve(root->left, num);
        solve(root->right, num);
    }
    int sumRootToLeaf(TreeNode *root)
    {
        ans = 0;
        solve(root, 0);
        return ans;
    }
};

//

// Approach - Recursion
// T.C : O(n)
// S.C : O(1) Auxiliary space (But O(n) system recursion stack space)
class Solution
{
public:
    int solve(TreeNode *root, int val)
    {
        if (!root)
        { // root == NULL
            return 0;
        }

        val = (2 * val) + root->val;

        if (root->left == NULL && root->right == NULL)
            return val;

        return solve(root->left, val) + solve(root->right, val);
    }

    int sumRootToLeaf(TreeNode *root)
    {
        return solve(root, 0);
    }
};