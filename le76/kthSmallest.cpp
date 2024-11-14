
class Solution
{
    int solve(TreeNode *root, int k, int &i)
    {
        if (root == NULL)
            return -1;

        int left = solve(root->left, k, i);
        if (left != -1)
        {
            return left;
        }

        // N

        i++;
        if (i == k)
            return root->val;

        // R

        return solve(root->right, k, i);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        int i = 0;
        return solve(root, k, i);
    }
};