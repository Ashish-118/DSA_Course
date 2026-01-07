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
#define mod 1000000007
class Solution
{
public:
    int getTotal(TreeNode *root)
    {
        if (!root)
            return 0;

        int l = getTotal(root->left);
        int r = getTotal(root->right);

        return l + r + root->val;
    }

    int dfs(TreeNode *root, long long &ans, int total)
    {
        if (!root)
            return 0;

        int l = dfs(root->left, ans, total);
        int r = dfs(root->right, ans, total);

        int subTree1 = l + r + root->val;
        int subTree2 = total - subTree1;
        ans = max(ans, subTree1 * 1LL * subTree2);

        return l + r + root->val;
    }
    int maxProduct(TreeNode *root)
    {
        int total = getTotal(root);

        long long ans = -1;
        dfs(root, ans, total);
        return ans % mod;
    }
};