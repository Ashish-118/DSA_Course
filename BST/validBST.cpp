class Solution
{
    bool isBST(TreeNode *root, long minVal, long maxVal)
    {
        if (!root)
            return true;
        if (root->val <= minVal || root->val >= maxVal)
            return false;

        return isBST(root->left, minVal, root->val) &&
               isBST(root->right, root->val, maxVal);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};
