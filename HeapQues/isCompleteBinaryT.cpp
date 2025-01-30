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
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }

    bool check(TreeNode *root, int i, int cnt)
    {
        if (root == NULL)
            return true;
        if (i >= cnt)
        {
            return false;
        }

        bool l = check(root->left, 2 * i + 1, cnt);
        bool r = check(root->right, 2 * i + 2, cnt);

        return l && r;
    }

public:
    bool isCompleteTree(TreeNode *root)
    {
        int count = countNodes(root);
        return check(root, 0, count);
    }
};