class Solution
{
public:
    bool dfs(TreeNode *&root, int sum, int limit)
    {
        if (!root)
            return false;

        sum += root->val;

        // Leaf node
        if (!root->left && !root->right)
        {
            if (sum < limit)
            {
                root = nullptr;
                return false;
            }
            return true;
        }

        bool leftOk = dfs(root->left, sum, limit);
        bool rightOk = dfs(root->right, sum, limit);

        // If both subtrees are insufficient, delete this node
        if (!leftOk && !rightOk)
        {
            root = nullptr;
            return false;
        }

        return true;
    }

    TreeNode *sufficientSubset(TreeNode *root, int limit)
    {
        dfs(root, 0, limit);
        return root;
    }
};
