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
    TreeNode *solve(TreeNode *root, int p, int q)
    {
        if (!root)
            return nullptr;
        if (root->val == p || root->val == q)
            return root;

        TreeNode *left = solve(root->left, p, q);
        TreeNode *right = solve(root->right, p, q);

        if (left && right)
            return root;
        else if (left)
            return left;
        else if (right)
            return right;

        return nullptr;
    }
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        vector<int> deepest;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int len = q.size();
            vector<int> v;

            for (int i = 0; i < len; i++)
            {
                auto front = q.front();
                q.pop();
                v.push_back(front->val);

                if (front->left)
                {
                    q.push(front->left);
                }
                if (front->right)
                {
                    q.push(front->right);
                }
            }

            deepest = v;
        }

        return solve(root, deepest[0], deepest.back());
    }
};