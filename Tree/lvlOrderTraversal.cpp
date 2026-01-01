class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        queue<TreeNode *> q;
        vector<vector<int>> res;

        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                currentLevel.push_back(node->val);

                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            res.push_back(currentLevel);
        }
        return res;
    }
};
