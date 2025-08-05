class Solution
{
public:
    void create(TreeNode *&root, int toInsert)
    {
        if (root == NULL)
        {
            root = new TreeNode(toInsert);
            return;
        }
        if (toInsert < root->val)
        {
            create(root->left, toInsert);
        }
        if (toInsert > root->val)
        {
            create(root->right, toInsert);
        }
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = NULL;
        for (auto &x : preorder)
        {
            create(root, x);
        }
        return root;
    }
};