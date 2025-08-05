class Solution
{
public:
    bool helper(TreeNode *p, TreeNode *q)
    {
        if (!p and !q)
            return true;
        if (!p or !q)
            return false;
        if (p->val != q->val)
            return false;
        bool left = helper(p->left, q->right);
        bool right = helper(p->right, q->left);
        return left and right;
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return helper(root->left, root->right);
    }
};